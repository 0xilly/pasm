#pragma once

#include <genrator/Generator.hh>
#include <genrator/arch/arm64/Arm64Registers.hh>
#include <genrator/arch/arm64/Arm64Instructions.hh>

#include <genrator/writer/Writer.hh>

class MacArm64Generator : Generator {
  private:
    PasmFile* pasm_file;
    std::string instructions;
    Writer* writer;
  private:
    Arm64Registers reserved;
    Arm64Instructions stack_pointer; 

  //Note(anita): This is for all the overrides from Generator.hh
  private:
    MacArm64Generator(Interp interp);
    auto generate(Mode mode) -> void override;

  private:
    auto create_label(std::string name) -> void;
    auto create_instruction() -> void;
    auto create_push() -> void;
    auto create_pop() -> void;
    auto process_labels() -> void;
    
};
