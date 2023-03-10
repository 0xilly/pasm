#include "fmt/core.h"
#include <interp/Interp.hh>

Interp::Interp(const char* target): lex(target) {

}

auto Interp::p_register() -> Register* {
  Token* reg = peek();
  if (!reg->is_scratch()) interp_error(fmt::format("Expected a register got {} instead", reg->to_string()));
  advance();
  return new Register(reg);
}

auto Interp::advance(u8 n) -> void { idx = idx + n; }
auto Interp::advance() -> void { advance(1); }

auto Interp::check(u8 n, Kind kind) -> bool {return peek(n)->kind == kind; }
auto Interp::check(Kind kind) -> bool { return check(1, kind); }

auto Interp::peek(u8 n) -> Token* { return lex.tokens.at(idx + n); }
auto Interp::peek() -> Token* { return peek(1); }
auto Interp::current() -> Token* {return peek(0);}

auto Interp::consume(Kind kind) -> Token* {
  Token* token{};
  if (check(kind)) {
    token = peek();
  } else {
    fmt::println("Interpiter Error: Illegal token {} found", token->lexme);
    fmt::println("                  Expected {}", kind_to_string(kind));
    std::exit(-1);
  }
  return peek();
}

auto Interp::interp_error(std::string msg) -> void {
 fmt::println("{}",msg);
 std::exit(-1);
}
