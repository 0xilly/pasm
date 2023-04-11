#pragma once

#include <Defs.hh>

#include "platform/Platform.hh"

#include <interp/Interp.hh>

class Generator {
  public:
    enum class Mode : u8 {
      TEXT,
      BIN,
      LINK,
    };
  public:
    explicit Generator(Interp interp){};
    virtual auto generate(Mode mode) -> void = 0;
    //virtual auto process() -> void = 0;
};

