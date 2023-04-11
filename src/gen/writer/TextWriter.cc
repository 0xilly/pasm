#include <gen/writer/TextWriter.hh>

TextWriter::TextWriter(const char* name, const char* target) : IWriter(name, target) {}

auto TextWriter::write_directive(Directive *directive) -> void {

}

auto TextWriter::write_instruction(Instruction *instruction) -> void {

}
