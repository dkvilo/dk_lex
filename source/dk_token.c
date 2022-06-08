/**
 * @file dk_token.c
 * @author David Kviloria (dkviloria@gmail.com)
 * @brief Token Implementation.
 * @version 0.1
 * @date 2022-06-08
 *
 * This code is on PUBLIC DOMAIN to allow for any use.
 *
 */
#include "dk_token.h"

dk_token_t*
dk_token_create(dk_token_type_t type, u8_t* p_data, u32_t size)
{
  dk_token_t* p_token = (dk_token_t*)malloc(sizeof(dk_token_t));
  p_token->type = type;
  p_token->p_data = p_data;
  p_token->size = size;
  return p_token;
}

void
dk_token_destroy(dk_token_t* p_token)
{
  free(p_token);
}

dk_token_t*
dk_token_next(dk_token_t* p_token)
{
  if (p_token->type == DK_TOKEN_END_OF_FILE)
    return NULL;
  return dk_token_create(DK_TOKEN_UNKNOWN, NULL, 0);
}
