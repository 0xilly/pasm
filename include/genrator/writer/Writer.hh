#pragma once

#include <ast/Ast.hh>
#include <any>

class Writer {
  public:
    Writer(const char* path);
    ~Writer();
  private:
    auto virtual write(std::string target) -> void = 0;
    auto virtual save() -> bool = 0;
    
};
