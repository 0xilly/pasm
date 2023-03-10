#include <ast/AstKind.hh>

const std::map<std::string, AstKind> ast_kind_map = {
#define AKind(ename, str) {str, AstKind::ename},
    AstKindList
#undef AKind
};

auto ast_name_to_kind(std::string name) -> AstKind {
  For(ast_kind_map) {
    if (it.first == name) {
      return it.second;
    }
  }
  return AstKind::INVALID;
}

auto ast_kind_to_name(AstKind kind) -> const std::string {
  For(ast_kind_map) {
    if (it.second == kind) {
      return it.first;
    }
  }
  return "INVALID";
}
