cmake_minimum_required(VERSION 3.20)

project(psalm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendor/fmt)

include_directories(include)


set(PSALM_SRC
  src/Main.cc

  src/interp/Scan.cc
  src/interp/Lex.cc

  src/token/Token.cc

  src/ast/AstKind.cc

  src/interp/Construct.cc
  src/interp/Label.cc

  src/interp/Interp.cc


  src/interp/Directive.cc
  src/interp/Instruction.cc

  src/generator/macos/MacArm64Gen.cc
)

add_definitions( -DDEBUG=1)

add_executable(${PROJECT_NAME} ${PSALM_SRC})

target_link_libraries(${PROJECT_NAME} fmt::fmt )

