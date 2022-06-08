# Handcrafted lexer written In c99

License Public Domain

# Building Instructions

```zsh
   make clean build

   ./build/kc example.kk
```

### Supported Syntax

```rust
struct person_t {
  str name;
  i32 age;
}

enum MY_ENUMS : i32 {
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
}

str name = "David";
i32 age = 23;
str occupation = "Programmer";
str address = "Tbilisi, Georgia";
bool is_available = false;
i32 result = age + 2;

str color = "darkgreen";
if is_available {
  str hello = "world";
}

if is_available {
  str my_string = "This is a relatively long string";
  if some_condition < 0 {
    i32 x = 1;
  }
}

```

### Lexer Output

```
Token(KEYWORD, struct)
Token(IDENTIFIER, person_t)
Token(OPEN_BRACKET)
Token(KEYWORD, str)
Token(IDENTIFIER, name)
Token(KEYWORD, i32)
Token(IDENTIFIER, age)
Token(CLOSE_BRACKET)
Token(KEYWORD, enum)
Token(IDENTIFIER, MY_ENUMS)
Token(DELIMITER, :)
Token(KEYWORD, i32)
Token(OPEN_BRACKET)
Token(IDENTIFIER, ONE)
Token(IDENTIFIER, TWO)
Token(IDENTIFIER, THREE)
Token(IDENTIFIER, FOUR)
Token(IDENTIFIER, FIVE)
Token(IDENTIFIER, SIX)
Token(CLOSE_BRACKET)
Token(KEYWORD, str)
Token(IDENTIFIER, name)
Token(OPERATOR, =)
Token(STRING, "David")
Token(SEMICOLON)
Token(KEYWORD, i32)
Token(IDENTIFIER, age)
Token(OPERATOR, =)
Token(NUMBER, 23)
Token(KEYWORD, str)
Token(IDENTIFIER, occupation)
Token(OPERATOR, =)
Token(STRING, "Programmer")
Token(SEMICOLON)
Token(KEYWORD, str)
Token(IDENTIFIER, address)
Token(OPERATOR, =)
Token(STRING, "Tbilisi, Georgia")
Token(SEMICOLON)
Token(KEYWORD, bool)
Token(IDENTIFIER, is_available)
Token(OPERATOR, =)
Token(KEYWORD, false)
Token(KEYWORD, i32)
Token(IDENTIFIER, result)
Token(OPERATOR, =)
Token(IDENTIFIER, age)
Token(OPERATOR, +)
Token(NUMBER, 2)
Token(KEYWORD, str)
Token(IDENTIFIER, color)
Token(OPERATOR, =)
Token(STRING, "darkgreen")
Token(SEMICOLON)
Token(KEYWORD, if)
Token(IDENTIFIER, is_available)
Token(OPEN_BRACKET)
Token(KEYWORD, str)
Token(IDENTIFIER, hello)
Token(OPERATOR, =)
Token(STRING, "world")
Token(SEMICOLON)
Token(CLOSE_BRACKET)
Token(KEYWORD, if)
Token(IDENTIFIER, is_available)
Token(OPEN_BRACKET)
Token(KEYWORD, str)
Token(KEYWORD, my_string)
Token(OPERATOR, =)
Token(STRING, "This is a relatively long string")
Token(SEMICOLON)
Token(KEYWORD, if)
Token(IDENTIFIER, some_condition)
Token(OPERATOR, <)
Token(NUMBER, 0)
Token(OPEN_BRACKET)
Token(KEYWORD, i32)
Token(IDENTIFIER, x)
Token(OPERATOR, =)
Token(NUMBER, 1)
Token(CLOSE_BRACKET)
Token(CLOSE_BRACKET)
Token(EOF)
 - Lexer Time: 0.000311
```

TODO:

- Extend to support more tokens
- Add support for statement blocks
- Add support for character literals
- Add support for floating point numbers
- Add support for preprocessor directives, macros, includes, etc.
- etc.
