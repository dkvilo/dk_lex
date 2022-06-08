/**
 * @file main.c
 * @author David Kviloria (dkviloria@gmail.com)
 * @brief Main
 * @date 2022-06-08
 *
 * This code is on PUBLIC DOMAIN to allow for any use.
 *
 */
#include "dk_ast.h"
#include "dk_lexer.h"
#include "dk_parser.h"
#include "dk_token.h"

#define DK_HASHMAP_INITIAL_CAPACITY 16

int
main(int argc, char** argv)
{

  DK_BENCHMARK_START(Lexer);

  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  u32_t size;
  u8_t* p_data = dk_read_file(argv[1], &size);
  if (!p_data) {
    printf("Failed to read file %s\n", argv[1]);
    return 1;
  }

  dk_hashmap_t* p_heap =
    dk_hashmap_create(sizeof(dk_token_t*) * DK_HASHMAP_INITIAL_CAPACITY);
#undef DK_HASHMAP_INITIAL_CAPACITY

  dk_lexer_t* p_lexer = dk_lexer_create(p_data, size * sizeof(u8_t));

  for (u64_t i = 0; i < size; i++) {

    // Parse the next token
    dk_token_t* p_token = dk_lexer_next_token(p_lexer);

    // Ingonre whitespace
    if (p_token->type == DK_TOKEN_WHITESPACE) {
      continue;
    }

    // Print token
    dk_lexer_print_token(p_token);
    if (p_token->type == DK_TOKEN_IDENTIFIER) {
      dk_hashmap_put(p_heap, i, p_token->p_data);
    }

    // Do not parse empty lines
    if (p_token->type == DK_TOKEN_END_OF_FILE) {
      break;
    }

#if 0
    u8_t* val = (u8_t*)dk_hashmap_get(p_heap, i);
    printf("Map: %s\n", val);
#endif

    p_lexer->cursor++;
    free(p_token);
  }

  // Free memory
  dk_lexer_destroy(p_lexer);
  free(p_data);

  DK_BENCHMARK_END(Lexer);

  return 0;
}
