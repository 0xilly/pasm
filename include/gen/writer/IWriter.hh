#pragma once

#include <ast/Ast.hh>

class IWriter {
  protected:
    const char* name;
    const char* target;
    const PasmFile* pasm;
    
  public:
    IWriter(const char* name, const char* target);

  protected:
    auto load(PasmFile* pasm) -> void;

    auto virtual write_directive(Directive* Directive) -> void = 0;
    auto virtual write_label(Label* lable) -> void = 0;
    auto virtual write_instruction(Instruction* instruction) -> void = 0;

    auto virtual save() -> bool = 0;
    
};
