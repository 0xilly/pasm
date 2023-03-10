#include <token/Token.hh>


Pos::Pos(const char* path, size start, size line, size column, size end) {
  this->path          = path;
  this->offset_start  = start;
  this->line          = line;
  this->column        = column;
  this->offset_end = end;
}

auto Pos::to_string() -> std::string {
  return fmt::format("Pos[path={}, offset_start={}, line={}, column={}, offset_end={}]", path, offset_start, line, column, offset_end);
}
Token::Token(std::string lexme, TokenKind kind, Pos pos) : pos(pos) {

    this->lexme = lexme;
    this->kind  = kind;
    this->pos   = pos;
}

Token::Token(TokenKind kind, Pos pos) : pos(pos) {
    this->kind  = kind;
    this->lexme = kind_to_string(this->kind);
    this->pos   = pos;
}

Token::Token(std::string lexme, Pos pos) : pos(pos){
    this->lexme = lexme;
    this->kind  = lexme_to_kind(this->lexme);
    this->pos   = pos;
}


auto Token::is_scratch() -> bool {
  return TokenKind::SCRATCH_START < kind && kind  < TokenKind::SCRATCH_END;
}

auto Token::is_number() -> bool {
  return TokenKind::NUMBER_START < kind && kind  < TokenKind::NUMBER_END;
}

auto Token::is_instruction() -> bool {
  return TokenKind::INSTRUCTION_START < kind && kind  < TokenKind::INSTRUCTION_END;
}
auto Token::to_string() -> std::string {
  return fmt::format("Token[lexme = {:^6}, kind= {:^16}, pos = {:^6}]", lexme, kind_to_string(kind), pos.to_string());
}

auto kind_to_string(TokenKind kind) -> std::string {
  For(tok_map) {
    if (it.second == kind) {
      return it.first;
    }
  }
  return "ident_literal";
}

auto lexme_to_kind(std::string lexme) -> TokenKind {
  For(tok_map) {
    if (it.first == lexme) {
      return it.second;
    }
  }
  return TokenKind::IDENT_LITERAL;
}
