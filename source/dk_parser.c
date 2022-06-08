/**
 * @file dk_parser.h
 * @author David Kviloria (dkviloria@gmail.com)
 * @brief Parser implementation.
 * @date 2022-06-08
 *
 * This code is on PUBLIC DOMAIN to allow for any use.
 *
 */
#include "dk_parser.h"

dk_parser_t*
dk_parser_create(dk_token_t* p_token)
{
  dk_parser_t* p_parser = (dk_parser_t*)dk_malloc(sizeof(dk_parser_t));
  p_parser->p_token = p_token;
  p_parser->p_next_token = p_token;
  return p_parser;
}

void
dk_parser_destroy(dk_parser_t* p_parser)
{
  free(p_parser);
}

dk_token_t*
dk_parser_next_token(dk_parser_t* p_parser)
{
  dk_token_t* p_token = p_parser->p_next_token;
  p_parser->p_next_token = dk_token_next(p_token);
  return p_token;
}

dk_token_t*
dk_parser_peek_token(dk_parser_t* p_parser)
{
  return p_parser->p_next_token;
}

dk_token_t*
dk_parser_consume_token(dk_parser_t* p_parser)
{
  dk_token_t* p_token = p_parser->p_next_token;
  p_parser->p_next_token = dk_token_next(p_token);
  return p_token;
}

dk_token_t*
dk_parser_consume_token_type(dk_parser_t* p_parser, dk_token_type_t type)
{
  dk_token_t* p_token = p_parser->p_next_token;
  if (p_token->type != type)
    return NULL;
  p_parser->p_next_token = dk_token_next(p_token);
  return p_token;
}

dk_token_t*
dk_parser_consume_token_data(dk_parser_t* p_parser, u8_t* p_data, u32_t size)
{
  dk_token_t* p_token = p_parser->p_next_token;
  if (p_token->size != size || memcmp(p_token->p_data, p_data, size) != 0)
    return NULL;
  p_parser->p_next_token = dk_token_next(p_token);
  return p_token;
}

dk_ast_t*
dk_parser_parse(dk_parser_t* p_parser)
{
  dk_ast_t* p_ast = dk_ast_create();
  dk_ast_t* p_current_ast = p_ast;
  dk_token_t* p_token = dk_parser_next_token(p_parser);
  while (p_token->type != DK_TOKEN_END_OF_FILE) {
    // TODO (David): handle other types of tokens.
    if (p_token->type == DK_TOKEN_STRING) {
      dk_ast_t* p_child_ast = dk_parser_parse(p_parser);
      dk_ast_add_child(p_current_ast, p_child_ast);
    } else {
      dk_ast_t* p_child_ast = dk_ast_create();
      dk_ast_set_token(p_child_ast, p_token);
      dk_ast_add_child(p_current_ast, p_child_ast);
    }
    p_token = dk_parser_next_token(p_parser);
  }
  return p_ast;
}
