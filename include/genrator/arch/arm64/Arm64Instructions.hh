#pragma once

#include <Defs.hh>

#include <map>

#define ARM_INSTRUCTIONS \
  AINST(MOV   , "mov"   , "move"                , 0xffffff) \
  AINST(ADD   , "add"   , "add"                 , 0xffffff) \
  AINST(SUB   , "sub"   , "sub"                 , 0xffffff) \
  AINST(DIV   , "div"   , "div"                 , 0xffffff) \
  AINST(MUL   , "mul"   , "mul"                 , 0xffffff) \
  AINST(BR    , "br"    , "branch"              , 0xffffff) \
  AINST(JMP   , "jmp"   , "jump"                , 0xffffff) \
  AINST(JNQ   , "jnq"   , "jump if not equals"  , 0xffffff) \
  AINST(JEQ   , "jeq"   , "jump if equals"      , 0xffffff) \
  AINST(CALL  , "call"  , "call"                , 0xffffff) \
  AINST(RET   , "ret"   , "retrun"              , 0xffffff) \

enum class Arm64Instructions {
  #define AINST(ename, name, description, value) ename = value,
    ARM_INSTRUCTIONS
  #undef AINST
};

struct Arm64Instruction {
  Arm64Instructions instruction;
  std::string       name;
  std::string       description;
  i32               value;
};

const std::map<Arm64Instructions, Arm64Instruction> instruction_map = {
  #define AINST(ename, name, description, value) {Arm64Instructions::ename, {Arm64Instructions::ename, name, description, value}},
    ARM_INSTRUCTIONS
  #undef AINST
};

