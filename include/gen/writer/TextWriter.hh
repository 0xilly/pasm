#pragma once

#include <gen/writer/IWriter.hh>

class TextWriter : IWriter {
  private:
    std::string buffer;
  public:
    TextWriter(const char* name, const char* target);

    auto write_directive(Directive* directive) -> void override;
    auto write_label(Label* directive) -> void override;
    auto write_instruction(Instruction* instruction) -> void override;
};
