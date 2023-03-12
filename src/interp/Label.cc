#include <interp/Interp.hh>

auto Interp::label() -> Label* {
  auto ident = consume(Kind::IDENT_LITERAL);
  std::vector<Instruction*> instructions;
  consume(TokenKind::COLON);
  consume(Kind::EOL);

  if (!check(Kind::TAB)) interp_error(fmt::format("Expected a tab got {} instead", peek()->lexme));

  for(;;) {
    auto instruct = instruction();
    if (check(Kind::COMMENT)) {
      //Todo(anita): Deal with these later and attach to the actual node
      consume(Kind::COMMENT);
    }

    instructions.push_back(instruct);
    consume(Kind::EOL);
    if (check(Kind::EOL)) break;
  }
  return new Label(ident, instructions);
}
