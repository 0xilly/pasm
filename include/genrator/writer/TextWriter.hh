#pragma once

#include <genrator/writer/Writer.hh>

class TextWriter : Writer {
  public:
    TextWriter(const char* path);
    ~TextWriter();
  private:
    auto write(std::string target) -> void override;
    auto save() -> bool override;
};
