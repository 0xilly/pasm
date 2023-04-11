#pragma once

#include <token/Token.hh>
#include <gen/platform/Platform.hh>
#include <gen/arch/arm64/Arm64Registers.hh>
#include <gen/arch/arm64/Arm64Instructions.hh>

#include <vector>
#include <map>

struct RegisteBindings {
  TokenKind pusdo;
  Arm64Register  binding; 
};

class Arm64Mapper {
  using Kind    = TokenKind;
  using ArmReg  = Arm64Registers;
  using ArmInst = Arm64Instructions;

  private:
    std::vector<Arm64Registers>       platform_reserved;
    std::map<Kind, Arm64Instruction>  internal_instruction_map;
    std::map<Kind, Arm64Register>     internal_register_map;

  private:
    auto map_instruction(Kind kind, ArmInst instruction) -> void;
    auto map_register(Kind kind, ArmReg reg) -> void;
  

  public:
    Arm64Mapper(Os os);
    auto get_instruction(Kind kind) -> Arm64Instruction;
    auto get_register(Kind kind) -> Arm64Register;
};
