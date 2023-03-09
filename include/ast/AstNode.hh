#pragma once

#include <token/Token.hh>
#include <Defs.hh>
#include <ast/AstKind.hh>


struct Ast;
struct Lable;

struct Instruction;
struct Regsiter;

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

struct Instruction : Ast {
  Token* op{};
};

struct Regsiter : Ast {
  Token* reg{};
  Regsiter(Token* op, Token* reg) {
    this->reg   = reg;
    this->kind  = AstKind::REGISTER;
    this->name  = ast_kind_to_name(this->kind);
  }
};

struct LableNode : Ast {
  Token* ident;
  std::vector<Instruction> instructions;
  LableNode(Token* ident, std::vector<Instruction> instructions) {
    this->ident         = ident;
    this->instructions  = instructions;
    this->kind          = AstKind::INSTRUCTION;
    this->name          = ast_kind_to_name(this->kind);
  }
};

struct Mov : Instruction {
  Token*    value{};
  Regsiter* reg{};

  Mov(Token* op, Token* value, Regsiter* reg) {
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
  Regsiter* target;

  Add(Token* op, Ast* left, Ast* right, Regsiter* target) {
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
  Regsiter* target;

  Sub(Token* op, Ast* left, Ast* right, Regsiter* target) {
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
  Regsiter* target;

  Div(Token* op, Ast* left, Ast* right, Regsiter* target) {
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
  Regsiter* target;

  Mul(Token* op, Ast* left, Ast* right, Regsiter* target) {
    this->op      = op;
    this->left    = left;
    this->right   = right;
    this->target  = target;
    this->kind    = AstKind::MUL;
    this->name    = ast_kind_to_name(this->kind);
  }
};
