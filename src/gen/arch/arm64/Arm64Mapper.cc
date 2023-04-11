
#include <gen/arch/arm64/Arm64Mapper.hh>

Arm64Mapper::Arm64Mapper(Os os) {
  switch (os) {
    case LINUX: {} break;
    case MACOS: {
      //Note(anita): x18 & x29 reserved by OSX
      //https://developer.apple.com/documentation/xcode/writing-arm64-code-for-apple-platforms
      platform_reserved.push_back(ArmReg::X18); // Reserved regsiter
      platform_reserved.push_back(ArmReg::X29); // Reserved regsiter
    } break;
    case WINDOWS: {} break;

  }
}

auto Arm64Mapper::get_register(Kind kind) -> Arm64Register {
}

auto Arm64Mapper::map_instruction(Kind kind, ArmInst instruction) -> void {
  internal_instruction_map.insert({kind, get_arm64_instruction(instruction)});
}

auto Arm64Mapper::map_register(Kind kind, ArmReg reg) -> void {
  internal_register_map.insert({kind, get_arm64_regstier(reg)});

}
