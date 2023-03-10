#include <interp/Interp.hh>

auto Interp::directive() -> Directive* {
  Token* ident  = current();
  Token* name   = consume(Kind::IDENT_LITERAL);
  Token* start  = consume(Kind::OPEN_PARAN);
  std::vector<Token*> values;

  for (;;) {
    if (check(Kind::CLOSE_PARAN)) break;

    values.push_back(consume(Kind::IDENT_LITERAL));
    if (check(Kind::COMMA)) {
      consume(Kind::COMMA);
    }
  }
  Token* end = consume(Kind::CLOSE_PARAN);
  return new Directive(ident, name, start, values, end);
  
}
