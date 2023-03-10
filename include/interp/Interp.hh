#pragma once

#include <interp/Lex.hh>
#include <ast/Ast.hh>

class Interp {
  private:
    using Kind = TokenKind;
    Lex lex;
    size idx = 0;
  public:
    Interp(const char* target);
  private:
    auto peek(u8 n) -> Token*;
    auto peek() -> Token*;
    auto current() -> Token*;

    auto check(u8 n, Kind kind) -> bool;
    auto check(Kind kind) -> bool;

    auto consume(Kind kind) -> Token*;

    auto advance(u8 n) -> void;
    auto advance() -> void;
    auto interp_error(std::string msg) -> void;
  private:
    auto directive() -> Directive*;
    auto p_register() -> Register*;

    auto instruction() -> Instruction*;

    auto mov() -> Mov*;
    auto add() -> Add*;
    auto sub() -> Sub*;
    auto div() -> Div*;
    auto mul() -> Mul*;
    
};
