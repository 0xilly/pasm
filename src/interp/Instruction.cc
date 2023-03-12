#include <interp/Interp.hh>

//Fixme(anita): created a padded literal to parse to get rid of these annoing token rules
auto Interp::instruction() -> Instruction* {
  consume(Kind::TAB);
  auto op = peek();
  switch(op->kind) {
    case Kind::MOV: return mov();
    case Kind::ADD: return add();
    case Kind::SUB: return sub();
    case Kind::DIV: return div();
    case Kind::MUL: return mul();
    default: {
      if (!op->is_instruction()) {
        interp_error(fmt::format("{} is not an instruction", op->to_string()));
      }
      interp_error(fmt::format("Instruction {} is not implenented", op->lexme));
    }
  }
  return nullptr;
}

auto Interp::mov() -> Mov* {
  
  Token* op = consume(Kind::MOV);
  consume(Kind::SPACE);

  Token* ident = peek();
  if (!ident->is_number()) interp_error(fmt::format("Expected a number got {} instead", ident->to_string()));
  advance();

  consume(Kind::SPACE);
  consume(Kind::RIGHT_ARROW);
  consume(Kind::SPACE);

  Register* reg = p_register();

  return new Mov(op, ident, reg);
}

auto Interp::add() -> Add* {

  auto op = peek();

  advance();
  consume(Kind::SPACE);
  auto left = p_register();
  consume(Kind::COMMA);

  consume(Kind::SPACE);
  auto right = p_register();

  consume(Kind::SPACE);
  consume(Kind::RIGHT_ARROW);
  consume(Kind::SPACE);

  auto target = p_register();
  return new Add(op, left, right, target);
}


auto Interp::sub() -> Sub* {
  auto op = peek();
  advance();

  consume(Kind::SPACE);
  auto left = p_register();
  consume(Kind::COMMA);
  consume(Kind::SPACE);
  auto right = p_register();

  consume(Kind::SPACE);
  consume(Kind::RIGHT_ARROW);
  consume(Kind::SPACE);

  auto target = p_register();
  return new Sub(op, left, right, target);
}

auto Interp::div() -> Div* {
  auto op = peek();
  advance();

  consume(Kind::SPACE);
  auto left = p_register();
  consume(Kind::COMMA);
  consume(Kind::SPACE);
  auto right = p_register();

  consume(Kind::SPACE);
  consume(Kind::RIGHT_ARROW);
  consume(Kind::SPACE);

  auto target = p_register();
  return new Div(op, left, right, target);
}

auto Interp::mul() -> Mul* {
  auto op = peek();
  advance();

  consume(Kind::SPACE);
  auto left = p_register();
  consume(Kind::COMMA);
  consume(Kind::SPACE);
  auto right = p_register();

  consume(Kind::SPACE);
  consume(Kind::RIGHT_ARROW);
  consume(Kind::SPACE);

  auto target = p_register();
  return new Mul(op, left, right, target);
}
