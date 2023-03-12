#include <interp/Interp.hh>
#include <interp/Lex.hh>
#include <fmt/core.h>

auto main(int argc, char** argv) -> int {
//  Lex lex(argv[1]);
//  For(lex.tokens) {
//    fmt::println("{}",it->to_string());
//  }

  Interp interp(argv[1]);

  return 0;
}
