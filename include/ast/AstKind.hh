#pragma once

#include <Defs.hh>
#include <map>
#include <string>

#define AstKindList \
  AKind(INVALID     , "INVALID") \
  AKind(FILE        , "FILE") \
  AKind(DIRECTIVE   , "DIRECTIVE_NODE") \
  AKind(REGISTER    , "REGISTER_NODE") \
  AKind(LABLE       , "LABEL_NODE") \
  AKind(INSTRUCTION , "INSTRUCTION_NODE") \
  AKind(MOV         , "MOV_NODE") \
  AKind(ADD         , "ADD_NODE") \
  AKind(SUB         , "SUB_NODE") \
  AKind(DIV         , "DIV_NODE") \
  AKind(MUL         , "MUL_NODE") \
  AKind(JMP         , "JMP_NODE") \


enum class AstKind : u8 {
  #define AKind(ename, str) ename,
    AstKindList
  #undef AstKind
};

auto ast_name_to_kind(std::string name) -> AstKind;
auto ast_kind_to_name(AstKind kind) -> const std::string;


