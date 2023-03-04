#pragma once

#include <Defs.hh>
#include <fmt/core.h>
#include <map>

enum class TokenKind : u8;

auto kind_to_string(TokenKind kind) -> std::string;
auto lexme_to_kind(std::string lexme) -> TokenKind;

struct Pos {
  const char* path  = {};
  u8 offset_start   = {};
  u8 line           = {};
  u8 column         = {};
  u8 offset_end     = {};

  Pos();
  Pos(const char* path, u8 start, u8 line, u8 column, u8 end) {
    this->path          = path;
    this->offset_start  = start;
    this->line          = line;
    this->column        = column; this->offset_end    = end;
  }

  auto to_string() -> std::string {
    return fmt::format("Pos[path={}, offset_start={}, line={}, column={}, offset_end={}]", path, offset_start, line, column, offset_end);
  }
};

struct Token {
    Pos pos = {};
    std::string lexme;
    TokenKind kind;

    Token(std::string lexme, TokenKind kind, Pos pos) {
      this->lexme = lexme;
      this->kind  = kind;
      this->pos   = pos;
    }

    Token(TokenKind kind, Pos pos) {
      this->kind  = kind;
      this->lexme = kind_to_string(this->kind);
      this->pos   = pos;
    }

    Token(std::string lexme, Pos pos) {
      this->lexme = lexme;
      this->kind  = lexme_to_kind(this->lexme);
      this->pos   = pos;
    }

    auto to_string() -> std::string {
      return fmt::format("Token[lexme={}, kind={}, pos={}]", lexme, kind_to_string(kind), pos.to_string());
    }

};

enum class TokenKind : u8 {
  EOL,
  _EOF,
  TAB,

  SCRATCH_START,
    S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    S7,
    S8,
    S9,
    S10,
    S11,
    S12,
    S13,
    S14,
  SCRATCH_END,

  FLOAT_START,
    F0,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
  FLOAT_END,

  INSTRUCTION_START,
    MOV,

    ADD,
    SUB,
    DIV,
    MUL,

    BR,
    JMP,
    JMPNQ,

    PUSH,
    POP,


    CALL,
    RET,
  INSTRUCTION_END,

  OPERATORS_START,
    COMMENT,
    DIRECTIVE,
    COLON,
    COMMA,
    RIGHT_ARROW,
  OPERATORS_END,

  LITERAL_START,
    IDENT_LITERAL,
    STRING_LITERAL,
    HEX_LITERAL,
    BINARY_LITERAL,
    DECIMAL_LITERAL,
  LITERAL_END,

};

std::map<std::string, TokenKind> token_map = {
  {"EOL", TokenKind::EOL},
  {"EOF", TokenKind::_EOF},

  {"s0"   , TokenKind::S0},
  {"s1"   , TokenKind::S1},
  {"s2"   , TokenKind::S2},
  {"s3"   , TokenKind::S3},
  {"s4"   , TokenKind::S4},
  {"s5"   , TokenKind::S5},
  {"s6"   , TokenKind::S6},
  {"s7"   , TokenKind::S7},
  {"s8"   , TokenKind::S8},
  {"s9"   , TokenKind::S9},
  {"s10"  , TokenKind::S10},
  {"s11"  , TokenKind::S11},
  {"s12"  , TokenKind::S12},
  {"s13"  , TokenKind::S13},
  {"s14"  , TokenKind::S14},


  {"f0"   , TokenKind::F0},
  {"f1"   , TokenKind::F1},
  {"f2"   , TokenKind::F2},
  {"f3"   , TokenKind::F3},
  {"f4"   , TokenKind::F4},
  {"f5"   , TokenKind::F5},
  {"f6"   , TokenKind::F6},
  {"f7"   , TokenKind::F7},
  {"f8"   , TokenKind::F8},
  {"f9"   , TokenKind::F9},
  {"f10"  , TokenKind::F10},
  {"f11"  , TokenKind::F11},
  {"f12"  , TokenKind::F12},
  {"f13"  , TokenKind::F13},
  {"f14"  , TokenKind::F14},

  {"comment"  , TokenKind::COMMENT},
  {"@"        , TokenKind::DIRECTIVE},
  {":"        , TokenKind::COLON},
  {","        , TokenKind::COMMA},
  {"->"       , TokenKind::RIGHT_ARROW},

  {"mov"  , TokenKind::MOV},
  {"add"  , TokenKind::ADD},
  {"sub"  , TokenKind::SUB},
  {"div"  , TokenKind::DIV},
  {"br"   , TokenKind::BR },
  {"jmp"  , TokenKind::JMP},
  {"jmpnq", TokenKind::JMPNQ},
  {"push" , TokenKind::PUSH},
  {"pop"  , TokenKind::POP},
  {"call" , TokenKind::CALL},
  {"ret"  , TokenKind::RET},

};

auto kind_to_string(TokenKind kind) -> std::string {
  For(token_map) {
    if (it.second == kind) {
      return it.first;
    }
  }
  return "ident_literal";
}

auto lexme_to_kind(std::string lexme) -> TokenKind {
  For(token_map) {
    if (it.first == lexme) {
      return it.second;
    }
  }
  return TokenKind::IDENT_LITERAL;
}

