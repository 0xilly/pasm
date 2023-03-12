#include <interp/Interp.hh>

auto Interp::construct() -> PasmFile* {
  std::vector<Ast*> asts;
  auto direct = directive();
  asts.push_back(direct);

  while (!check(Kind::_EOF)) {
    switch(peek()->kind) {
      case Kind::DIRECTIVE: {
        auto d2 = directive();
        asts.push_back(d2);
      } break;
      case Kind::IDENT_LITERAL: {
        auto lbl = label();
        asts.push_back(lbl);
      }
      case Kind::EOL: {
        consume(Kind::EOL);
      } break;
      default: {
        interp_error(fmt::format("errors at top level of the interpreter phase\n {}", peek()->to_string()));
      }
    }
  
  }
  return new PasmFile(asts);
}
