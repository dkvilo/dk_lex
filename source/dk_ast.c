/**
 * @file dk_ast.c
 * @author David Kviloria (dkviloria@gmail.com)
 * @brief Abstract Syntax Tree implementation.
 * @date 2022-06-08
 *
 * This code is on PUBLIC DOMAIN to allow for any use.
 *
 */
#include "dk_ast.h"

dk_ast_t*
dk_ast_create()
{
  dk_ast_t* p_ast = (dk_ast_t*)dk_malloc(sizeof(dk_ast_t));
  p_ast->p_left = NULL;
  p_ast->p_right = NULL;
  return p_ast;
}

void
dk_ast_add_child(dk_ast_t* p_ast, dk_ast_t* p_child)
{
  if (p_ast->p_left == NULL)
    p_ast->p_left = p_child;
  else
    p_ast->p_right = p_child;
}

void
dk_ast_set_token(dk_ast_t* p_ast, dk_token_t* p_token)
{
  p_ast->p_token = p_token;
}

void
dk_ast_print(dk_ast_t* p_ast)
{
  if (p_ast == NULL)
    return;
  printf("%s", p_ast->p_token->p_data);
  if (p_ast->p_left != NULL)
    printf("(");
  dk_ast_print(p_ast->p_left);
  if (p_ast->p_left != NULL)
    printf(")");
  if (p_ast->p_right != NULL)
    printf("(");
  dk_ast_print(p_ast->p_right);
  if (p_ast->p_right != NULL)
    printf(")");
}
