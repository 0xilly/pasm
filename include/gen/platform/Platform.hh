#pragma once

#include <Defs.hh>
#include <string>

#define PLATFORMS_LIST \
  PLAT(LINUX  , "linux") \
  PLAT(MACOS  , "macos") \
  PLAT(WINDOWS, "linux") \

enum Os : u8 {
  #define PLAT(ename, name) ename,
    PLATFORMS_LIST
  #undef PLAT
};

auto os_to_name(Os os) -> std::string;
