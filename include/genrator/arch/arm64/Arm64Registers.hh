#pragma once

#include <Defs.hh>
#include <map>
#include <utility>

//Fixme(anita): Add actual registers numbers
#define ARM_REGISTERS \
  AREG(X0   , "x0"  , "Scratch Register 0"  , 0xfffffff) \
  AREG(X1   , "x1"  , "Scratch Register 1"  , 0xfffffff) \
  AREG(X2   , "x2"  , "Scratch Register 2"  , 0xfffffff) \
  AREG(X3   , "x3"  , "Scratch Register 3"  , 0xfffffff) \
  AREG(X4   , "x4"  , "Scratch Register 4"  , 0xfffffff) \
  AREG(X5   , "x5"  , "Scratch Register 5"  , 0xfffffff) \
  AREG(X6   , "x6"  , "Scratch Register 6"  , 0xfffffff) \
  AREG(X7   , "x7"  , "Scratch Register 7"  , 0xfffffff) \
  AREG(X8   , "x8"  , "Scratch Register 8"  , 0xfffffff) \
  AREG(X9   , "x9"  , "Scratch Register 9"  , 0xfffffff) \
  AREG(X10  , "x10" , "Scratch Register 10" , 0xfffffff) \
  AREG(X11  , "x11" , "Scratch Register 11" , 0xfffffff) \
  AREG(X12  , "x12" , "Scratch Register 12" , 0xfffffff) \
  AREG(X13  , "x13" , "Scratch Register 13" , 0xfffffff) \
  AREG(X14  , "x14" , "Scratch Register 14" , 0xfffffff) \
  AREG(X15  , "x15" , "Scratch Register 15" , 0xfffffff) \
  AREG(X16  , "x16" , "Scratch Register 16" , 0xfffffff) \
  AREG(X17  , "x17" , "Scratch Register 17" , 0xfffffff) \
  AREG(X18  , "x18" , "Scratch Register 18" , 0xfffffff) \
  AREG(X19  , "x19" , "Scratch Register 19" , 0xfffffff) \
  AREG(X20  , "x20" , "Scratch Register 20" , 0xfffffff) \
  AREG(X21  , "x21" , "Scratch Register 21" , 0xfffffff) \
  AREG(X22  , "x22" , "Scratch Register 22" , 0xfffffff) \
  AREG(X23  , "x23" , "Scratch Register 23" , 0xfffffff) \
  AREG(X24  , "x24" , "Scratch Register 24" , 0xfffffff) \
  AREG(X25  , "x25" , "Scratch Register 25" , 0xfffffff) \
  AREG(X26  , "x26" , "Scratch Register 26" , 0xfffffff) \
  AREG(X27  , "x27" , "Scratch Register 27" , 0xfffffff) \
  AREG(X28  , "x28" , "Scratch Register 28" , 0xfffffff) \
  AREG(X29  , "x29" , "Scratch Register 29" , 0xfffffff) \
  AREG(X30  , "x30" , "Scratch Register 30" , 0xfffffff) \


enum class Arm64Registers {
  #define AREG(ENAME, name, description, value) ENAME = value,
    ARM_REGISTERS
  #undef AREG
};

struct Arm64Register {
  Arm64Registers  reg;
  std::string     name;
  std::string     description;
  i32             value;
};

const std::map<Arm64Registers, Arm64Register> register_map = {
  #define AREG(ENAME, name, description, value) {Arm64Registers::ENAME, {Arm64Registers::ENAME, name, description, value}},
    ARM_REGISTERS
  #undef AREG
};

