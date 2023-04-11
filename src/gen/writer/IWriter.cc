#include <gen/writer/IWriter.hh>

IWriter::IWriter(const char* name, const char* target) {
  this->name    = name;
  this->target  = target;
}

auto IWriter::load(PasmFile* pasm) -> void {
  this->pasm = pasm;
}
