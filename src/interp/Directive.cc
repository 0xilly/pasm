#include <interp/Interp.hh>

auto Interp::directive() -> Directive* {
  auto ident  = current();
  auto name   = consume(Kind::IDENT_LITERAL);
  auto start  = consume(Kind::OPEN_PARAN);
  std::vector<Token*> values;

  for (;;) {
    if (check(Kind::CLOSE_PARAN)) break;

    auto idents = consume(Kind::IDENT_LITERAL);

    values.push_back(idents);
    if (check(Kind::COMMA)) {
      consume(Kind::COMMA);
    }
  }
  auto end = consume(Kind::CLOSE_PARAN);
  return new Directive(ident, name, start, values, end);
  
}
