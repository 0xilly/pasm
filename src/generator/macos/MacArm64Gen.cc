#include <genrator/platform/macos/MacArm64Gen.hh>

MacArm64Generator::MacArm64Generator(Interp interp) : Generator(interp) {
  this->pasm_file = interp.pasm_file;
}

auto MacArm64Generator::generate(Mode mode) -> void {
  using Kind = AstKind;
  this->reserved = Arm64Registers::X19;
  For(pasm_file->asts) {
    switch(it->kind) { case Kind::LABLE: {
        Label* label = (Label*)it;

      } break;
      default: break;
    }
  }
}

auto MacArm64Generator::create_instruction() -> void {

}

auto MacArm64Generator::create_push() -> void {

}


auto MacArm64Generator::create_pop() -> void {

}
