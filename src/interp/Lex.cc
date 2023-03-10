#include "ast/AstKind.hh"
#include <interp/Lex.hh>
#include <interp/Scan.hh>

Lex::Lex(const char* target) {
  Scan scan(target);
  buffer = scan.buffer;
  this->target = target;
  this->scan();
}

auto Lex::peek(u8 n) -> char { return buffer[idx + n]; }
auto Lex::peek() -> char { return peek(0); }

auto Lex::advance(u8 n) -> void {
  idx = idx + n;
  column = column + n;
}

auto Lex::advance() -> void { advance(1); }

auto Lex::check(u8 n, char c) -> bool { return peek(n) == c; }
auto Lex::check(char c) -> bool { return check(0, c); }

auto Lex::scan() -> void {
  while(peek() != '\0') {
    size start = idx;
    switch(peek()) {
      case '\n': {
        add_token(Kind::EOL, start);
        column = 1;
        line++;
        advance();
      } break;
      case '\t': {
        add_token(Kind::TAB, start);
        advance();
      } break;
      case ' ': {
        add_token(Kind::SPACE, start);
        advance();
      } break;
      case '#': { // comment
        auto comment = lex_comment(); 
        add_token(comment);
      } break;
      case  '@': {
        add_token(Kind::DIRECTIVE, start);
        advance();
      } break;
      case ',': {
        add_token(Kind::COMMA, start);
        advance();
      } break;
      case ':': {
        add_token(Kind::COLON, start);
        advance();
      } break;
      case '-': {
        advance();
        if (check('>')) {
          add_token(Kind::RIGHT_ARROW, start);
        } else {
          Panic("Error: Lexing right arrow")
        }
        advance();
      } break;
      case '"': {
        advance();
        auto str = concat_str();
        add_token(str, Kind::STRING_LITERAL, start);
      } break;
      case '(': {
        add_token(Kind::OPEN_PARAN, start);
        advance();
      } break;
      case ')': {
        add_token(Kind::CLOSE_PARAN, start);
        advance();
      }
      default: {
        Token* token{};
        if (is_digit()) {
          token = concat_num();
        } else {
          token = concat_ident();
        }
          add_token(token);
          advance();
      } break;
    }
  }
  add_token(Kind::_EOF, idx);
}

auto Lex::lex_comment() -> Token* {
  size start    = idx;
  size _column  = column;
  std::string str = {};
  while (!check(1, '\n')) {
    str.push_back(peek());
    advance();
  }
  return new Token(str, Kind::COMMENT, Pos(target, start, line, _column, idx));
}

auto Lex::concat_num() -> Token* {
  std::string str = "";
  auto start = idx;
  auto _column = column;

  if (check('0')) {
    advance();
    if (check('b')) {
      advance();
      auto binary = concat_binary();
      str.append(binary);
      return new Token(binary, Kind::BINARY_LITERAL, Pos(target, start, line, _column, idx));
    } else if(check('x')) {
      advance();
      auto hex = concat_hex();
      str.append(hex);
      return new Token(hex, Kind::HEX_LITERAL, Pos(target, start, line, _column, idx));
    }
  }
  auto digit = concat_digit();
  return new Token(digit, Kind::DECIMAL_LITERAL, Pos(target, start, line, _column, idx));
}

auto Lex::concat_ident() -> Token* {
  auto start = idx;
  std::string str = "";

  while(is_alpha_num()) {
    str.push_back(peek(0));
    advance();
  }

  return new Token(str, Pos(target, start, line, column, idx));
}

auto Lex::concat_str() -> std::string {
  std::string str = "";
  while(!check('"')) {
    str.push_back(peek(0));
    advance();
  }
  advance();
  return str;
}

auto Lex::concat_digit() -> std::string {
  std::string str = "";
  while (is_digit()) {
    str.push_back(peek(0));
    advance();
  }
  return str;
}

auto Lex::concat_hex() -> std::string {
  std::string str = "";
  while(!is_hex()) {
    str.push_back(peek(0));
    advance();
  }
  return str;
}

auto Lex::concat_binary() -> std::string {
  std::string str = "";
  while(!is_binary()) {
    str.push_back(peek(0));
    advance();
  }
  return str;
}

auto Lex::is_digit() -> bool {return peek(0) >= '0' && peek(0) <= '9';}
auto Lex::is_hex() -> bool {return (peek(0) >= 'A' && peek(0) <= 'F') || (peek(0) >= 'a' && peek(0) <= 'f') || is_digit();}
auto Lex::is_binary() -> bool {return (peek(0) == '0') || (peek(0) == '1');}

auto Lex::is_letter() -> bool { return (peek(0) >= 'a' && peek(0) <= 'z') || (peek(0) >= 'A' && peek(0) <= 'Z'); }
auto Lex::is_alpha_num() -> bool { return is_letter() || is_digit(); }
auto Lex::is_ident() -> bool { return is_digit() || is_letter() || peek(0) == '_'; }


auto Lex::add_token(Token* token) -> void {
  tokens.push_back(token);
}

auto Lex::add_token(Kind kind, size start) -> void {
  auto token = new Token(kind, Pos(target, start, line, column, idx));
  add_token(token);
}

auto Lex::add_token(std::string lexme, Kind kind, size start) -> void {
  auto token = new Token(lexme, kind, Pos(target, start, line, column, idx));
  add_token(token);
}
