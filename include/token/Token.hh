#pragma once

#include <Defs.hh>
#include <fmt/core.h>
#include <map>


#define TOKEN_DEF \
  Tok(EOL, "EOL") \
  Tok(_EOF, "EOF") \
  Tok(TAB, "TAB") \
  Tok(SPACE, "SPACE") \
  Tok(SCRATCH_START, "") \
    Tok(S0,  "s0") \
    Tok(S1,  "s1") \
    Tok(S2,  "s2") \
    Tok(S3,  "s3") \
    Tok(S4,  "s4") \
    Tok(S5,  "s5") \
    Tok(S6,  "s6") \
    Tok(S7,  "s7") \
    Tok(S8,  "s8") \
    Tok(S9,  "s9") \
    Tok(S10, "s10") \
    Tok(S11, "s11") \
    Tok(S12, "s12") \
    Tok(S13, "s13") \
    Tok(S14, "s14") \
  Tok(SCRATCH_END, "") \
  Tok(FLOAT_START, "") \
    Tok(F0,  "F0") \
    Tok(F1,  "F1") \
    Tok(F2,  "F2") \
    Tok(F3,  "F3") \
    Tok(F4,  "F4") \
    Tok(F5,  "F5") \
    Tok(F6,  "F6") \
    Tok(F7,  "F7") \
    Tok(F8,  "F8") \
    Tok(F9,  "F9") \
    Tok(F10, "F10") \
    Tok(F11, "F11") \
    Tok(F12, "F12") \
    Tok(F13, "F13") \
    Tok(F14, "F14") \
  Tok(FLOAT_END, "") \
  Tok(INSTRUCTION_START, "") \
    Tok(MOV   , "mov" ) \
    Tok(SUB   , "sub" ) \
    Tok(DIV   , "div" ) \
    Tok(MUL   , "mul" ) \
    Tok(BR    , "br"  ) \
    Tok(JMP   , "jmp" ) \
    Tok(JNQ   , "jnq" ) \
    Tok(JEQ   , "jeq" ) \
    Tok(PUSH  , "push") \
    Tok(POP   , "pop" ) \
    Tok(CALL  , "call") \
    Tok(RET   , "ret" ) \
  Tok(INSTRUCTION_END, "") \
  \
  Tok(COMMENT     ,  "comment") \
  Tok(DIRECTIVE   ,  "@"  ) \
  Tok(COLON       ,  ":"  ) \
  Tok(COMMA       ,  ","  ) \
  Tok(RIGHT_ARROW ,  "->" ) \
  \
  Tok(IDENT_LITERAL   , "ident_literal"   ) \
  Tok(STRING_LITERAL  , "string_literal"  ) \
  Tok(HEX_LITERAL     , "hex_literal"     ) \
  Tok(BINARY_LITERAL  , "binary_literal"  ) \
  Tok(DECIMAL_LITERAL , "decimal_literal" ) \



enum class TokenKind : u8 {
  #define Tok(ename, str) ename,
    TOKEN_DEF
  #undef Tok
};

const std::map<std::string, TokenKind> tok_map = {
  #define Tok(ename, str) {str, TokenKind::ename},
    TOKEN_DEF
  #undef Tok
};

auto kind_to_string(TokenKind kind) -> std::string;
auto lexme_to_kind(std::string lexme) -> TokenKind;

struct Pos {
  const char* path  = {};
  size offset_start   = {};
  size line           = {};
  size column         = {};
  size offset_end     = {};

  Pos();
  Pos(const char* path, size start, size line, size column, size end) {
    this->path          = path;
    this->offset_start  = start;
    this->line          = line;
    this->column        = column; this->offset_end = end;
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
