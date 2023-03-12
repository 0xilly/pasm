#pragma once

#include <token/Token.hh>
#include <Defs.hh>
#include <ast/AstKind.hh>


struct Ast;
struct PasmFile;
struct Label;

struct Instruction;
struct Register;
struct Directive;

//JMP
struct Jmp;

//Mov Instructions
struct Mov;

//Add
struct Add;

struct Sub;

struct Div;

struct Mul;

struct Ast {
  std::string name;
  AstKind kind;
};

struct PasmFile {
  std::vector<Ast*> asts;

  PasmFile(std::vector<Ast*> asts) {
    this->asts = asts;
  }
};

struct Instruction : Ast {
  Token* op{};
};

struct Register : Ast {
  Token* reg{};
  Register(Token* reg) {
    this->reg   = reg;
    this->kind  = AstKind::REGISTER;
    this->name  = ast_kind_to_name(this->kind);
  }
};

struct Label : Ast {
  Token* ident;
  std::vector<Instruction*> instructions;
  Label(Token* ident, std::vector<Instruction*> instructions) {
    this->ident         = ident;
    this->instructions  = instructions;
    this->kind          = AstKind::INSTRUCTION;
    this->name          = ast_kind_to_name(this->kind);
  }
};

struct Directive : Ast {
  Token* ident;
  Token* id;
  Token* start;
  std::vector<Token*> values;
  Token* end;

  Directive(Token* ident, Token* id, Token* start, std::vector<Token*> values, Token* end) {
    this->ident   = ident;
    this->id      = id;
    this->start   = start;
    this->values  = values;
    this->end     = end;
    this->kind    = AstKind::DIRECTIVE;
    this->name    = ast_kind_to_name(this->kind);
  }
};

struct Mov : Instruction {
  Token*    value{};
  Register* reg{};

  Mov(Token* op, Token* value, Register* reg) {
    this->op    = op;
    this->value = value;
    this->reg   = reg;
    this->kind  = AstKind::MOV;
    this->name  = ast_kind_to_name(this->kind);
  } 
};

struct Add : Instruction {
  Ast* left{};
  Ast* right{};
  Register* target;

  Add(Token* op, Ast* left, Ast* right, Register* target) {
    this->op      = op;
    this->left    = left;
    this->right   = right;
    this->target  = target;
    this->kind    = AstKind::ADD;
    this->name    = ast_kind_to_name(this->kind);
  }
};

struct Sub : Instruction {
  Ast* left{};
  Ast* right{};
  Register* target;

  Sub(Token* op, Ast* left, Ast* right, Register* target) {
    this->op      = op;
    this->left    = left;
    this->right   = right;
    this->target  = target;
    this->kind    = AstKind::SUB;
    this->name    = ast_kind_to_name(this->kind);
  }
};

struct Div : Instruction {
  Ast* left{};
  Ast* right{};
  Register* target;

  Div(Token* op, Ast* left, Ast* right, Register* target) {
    this->op      = op;
    this->left    = left;
    this->right   = right;
    this->target  = target;
    this->kind    = AstKind::DIV;
    this->name    = ast_kind_to_name(this->kind);
  }
};

struct Mul : Instruction {
  Ast* left{};
  Ast* right{};
  Register* target;

  Mul(Token* op, Ast* left, Ast* right, Register* target) {
    this->op      = op;
    this->left    = left;
    this->right   = right;
    this->target  = target;
    this->kind    = AstKind::MUL;
    this->name    = ast_kind_to_name(this->kind);
  }
};
