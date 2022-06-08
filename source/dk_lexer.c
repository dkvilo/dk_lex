/**
 * @file dk_lexer.c
 * @author David Kviloria (dkviloria@gmail.com)
 * @brief Lexer implementation.
 * @date 2022-06-08
 *
 * This code is on PUBLIC DOMAIN to allow for any use.
 *
 */
#include "dk_lexer.h"

#if !defined(__DK_H__)
#include "dk.h"
#endif

dk_lexer_t*
dk_lexer_create(u8_t* p_data, u32_t size)
{
  dk_lexer_t* p_lexer = (dk_lexer_t*)dk_malloc(sizeof(dk_lexer_t));
  p_lexer->p_data = p_data;
  p_lexer->size = size;
  p_lexer->cursor = 0;
  return p_lexer;
}

void
dk_lexer_destroy(dk_lexer_t* p_lexer)
{
  free(p_lexer);
}

u8_t
dk_lexer_peak(dk_lexer_t* p_lexer)
{
  if (p_lexer->cursor >= p_lexer->size)
    return 0;
  return p_lexer->p_data[p_lexer->cursor];
}

dk_token_t*
dk_lexer_next_token(dk_lexer_t* p_lexer)
{
  u8_t* p_data = p_lexer->p_data;
  u32_t size = p_lexer->size;
  u32_t* cursor = &p_lexer->cursor;
  u8_t c = dk_lexer_peak(p_lexer);

  if (c == 0)
    return dk_token_create(DK_TOKEN_END_OF_FILE, NULL, 0);

  if (IsWhiteSpace(c)) {
    while (IsWhiteSpace(c)) {
      p_lexer->cursor++;
      c = p_data[p_lexer->cursor];
    }
    return dk_token_create(
      DK_TOKEN_WHITESPACE, p_data + *cursor, p_lexer->cursor - *cursor);
  }

  else if (c == '/') {
    while (c != '\n') {
      p_lexer->cursor++;
      c = p_data[p_lexer->cursor];
    }
    return dk_token_create(
      DK_TOKEN_COMMENT, p_data + *cursor, p_lexer->cursor - *cursor);
  }

  else if (IsAlphaNumUnderScore(c) && !IsNumber(c)) {
    bool is_keyword = false;

    u8_t* p_ident = (u8_t*)dk_malloc(sizeof(u8_t) * (size - *cursor));
    u32_t ident_size = 0;
    while (IsAlphaNumUnderScore(c)) {
      for (u32_t i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strncmp((char*)p_data + *cursor,
                    keywords[i].keyword,
                    strlen(keywords[i].keyword)) == 0) {
          is_keyword = true;
          break;
        }
      }
      p_ident[ident_size++] = c;
      c = p_data[++(*cursor)];
    }

    if (is_keyword) {
      return dk_token_create(DK_TOKEN_KEYWORD, p_ident, ident_size);
    }
    return dk_token_create(DK_TOKEN_IDENTIFIER, p_ident, ident_size);
  }

#if 1
  else if (IsOperator(c)) {
    u8_t* p_op = (u8_t*)dk_malloc(sizeof(u8_t) * (size - *cursor));
    u32_t op_size = 0;
    while (IsOperator(c)) {
      p_op[op_size++] = c;
      c = p_data[++(*cursor)];
    }
    p_op[op_size] = 0;
    return dk_token_create(DK_TOKEN_OPERATOR, p_op, op_size);
  }

  else if (IsDelimiter(c)) {
    u8_t* p_deli = (u8_t*)dk_malloc(sizeof(u8_t) * (size - *cursor));
    u32_t deli_size = 0;
    while (IsDelimiter(c)) {
      p_deli[deli_size++] = c;
      c = p_data[++(*cursor)];
    }
    p_deli[deli_size] = 0;
    return dk_token_create(DK_TOKEN_DELIMITER, p_deli, deli_size);
  }

  else if (IsString(c)) {
    u8_t* p_str = (u8_t*)dk_malloc(sizeof(u8_t) * (size - *cursor));
    u32_t str_size = 0;
    c = p_data[++(*cursor)];
    while (c != 0 && c != '"') {
      p_str[str_size++] = c;
      c = p_data[++(*cursor)];
    }
    p_str[str_size] = 0;
    return dk_token_create(DK_TOKEN_STRING, p_str, str_size);
  }

  else if (c == '{') {
    u8_t* p_str = (u8_t*)dk_malloc(sizeof(u8_t) * (size - *cursor));
    u32_t str_size = 0;
    c = p_data[++(*cursor)];
    while (c == '}') {
      p_str[str_size++] = c;
      c = p_data[++(*cursor)];
    }
    p_str[str_size] = 0;
    return dk_token_create(DK_TOKEN_OPEN_BRACE, p_str, str_size);
  }

  else if (c == '}') {
    u8_t* p_str = (u8_t*)dk_malloc(sizeof(u8_t) * (size - *cursor));
    u32_t str_size = 0;
    c = p_data[++(*cursor)];
    while (c == ';') {
      p_str[str_size++] = c;
      c = p_data[++(*cursor)];
    }
    p_str[str_size] = 0;
    return dk_token_create(DK_TOKEN_CLOSE_BRACE, p_str, str_size);
  }

  else if (IsNumber(c)) {
    u8_t* p_num = (u8_t*)dk_malloc(sizeof(u8_t) * (size - *cursor));
    u32_t num_size = 0;
    while (IsNumber(c)) {
      p_num[num_size++] = c;
      c = p_data[++(*cursor)];
    }
    p_num[num_size] = 0;
    return dk_token_create(DK_TOKEN_NUMBER, p_num, num_size);
  }

  else if (IsSemiColon(c)) {
    p_lexer->cursor++;
    return dk_token_create(DK_TOKEN_SEMICOLON, NULL, 0);
  }
#endif
  return dk_token_create(DK_TOKEN_UNKNOWN, NULL, 0);
}

/**
 * @brief Pretty Print, Please
 *
 * @param p_token
 */
void
dk_lexer_print_token(dk_token_t* p_token)
{
  printf("Token(");
  switch (p_token->type) {
    case DK_TOKEN_END_OF_FILE:
      printf("EOF");
      break;
    case DK_TOKEN_END_OF_LINE:
      printf("EOL");
      break;
    case DK_TOKEN_WHITESPACE:
      printf("WHITESPACE");
      break;
    case DK_TOKEN_KEYWORD:
      printf("KEYWORD, %s", p_token->p_data);
      break;
    case DK_TOKEN_DATA_TYPE:
      printf("DATA_TYPE, %s", p_token->p_data);
      break;
    case DK_TOKEN_IDENTIFIER:
      printf("IDENTIFIER, %s", p_token->p_data);
      break;
    case DK_TOKEN_OPERATOR:
      printf("OPERATOR, %s", p_token->p_data);
      break;
    case DK_TOKEN_STRING:
      printf("STRING, \"%s\"", p_token->p_data);
      break;
    case DK_TOKEN_NUMBER:
      printf("NUMBER, %s", p_token->p_data);
      break;
    case DK_TOKEN_UNKNOWN:
      printf("UNKNOWN", p_token->p_data);
      break;
    case DK_TOKEN_COMMA:
      printf("COMMA");
      break;
    case DK_TOKEN_OPEN_BRACE:
      printf("OPEN_BRACKET");
      break;
    case DK_TOKEN_CLOSE_BRACE:
      printf("CLOSE_BRACKET");
      break;
    case DK_TOKEN_AMPERSAND:
      printf("AMPERSAND");
      break;
    case DK_TOKEN_ERROR:
      printf("ERROR", p_token->p_data);
      break;
    case DK_TOKEN_SEMICOLON:
      printf("SEMICOLON");
      break;
    case DK_TOKEN_DELIMITER:
      printf("DELIMITER, %s", p_token->p_data);
      break;
    case DK_TOKEN_COMMENT:
      printf("COMMENT", p_token->p_data);
      break;
    default:
      printf("NOT SUPPORTED");
      break;
  }
  printf(")\n");
}

void
dk_lexer_print(dk_lexer_t* p_lexer)
{
  printf("Lexer:\n");
  printf("  data: %s\n", p_lexer->p_data);
  printf("  size: %d\n", p_lexer->size);
  printf("  cursor: %d\n", p_lexer->cursor);
}
