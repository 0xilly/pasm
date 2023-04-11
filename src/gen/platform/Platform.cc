#include <gen/platform/Platform.hh>

auto os_to_name(Os os) -> std::string {
  switch(os) {
    #define PLAT(ename, name) case ename: return name;
      PLATFORMS_LIST
    #undef PLAT
  }
}
