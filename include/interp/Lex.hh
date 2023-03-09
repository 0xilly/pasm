#pragma once

#include <token/Token.hh>

#include <vector>

class Lex {
  public:
    std::vector<Token*> tokens;
  public:
    Lex(const char* target);

  private:
    char* buffer {};
    const char* target;

    size idx    = 0;
    size line   = 1;
    size column = 1;
  private:
    using Kind = TokenKind;

    auto advance(u8 n) -> void;
    auto advance() -> void;

    auto peek(u8 n) -> char;
    auto peek() -> char;

    auto check(u8 n, char c) -> bool;
    auto check(char c) -> bool;

    auto scan() -> void;
    
    auto lex_comment() -> Token*;

    auto add_token(Token* token) -> void;
    auto add_token(Kind kind, size start) -> void;
    auto add_token(std::string lexme, Kind kind, size start) -> void;

    auto concat_str() -> std::string;
    auto concat_hex() -> std::string;
    auto concat_digit() -> std::string;
    auto concat_binary() -> std::string;

    auto concat_num() -> Token*;
    auto concat_ident() -> Token*;

    auto is_hex() -> bool;
    auto is_digit() -> bool;
    auto is_binary() -> bool;

    auto is_letter() -> bool;
    auto is_alpha_num() -> bool;
    auto is_ident() -> bool;

    auto is_num() -> bool;


};
