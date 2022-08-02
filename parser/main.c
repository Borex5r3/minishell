/*
 * Filename: /home/guts/Desktop/minishell/main.c
 * Path: /home/guts/Desktop/minishell
 * Created Date: Monday, July 18th 2022, 1:24:04 am
 * Author: Hamza
 * 
 * Copyright (c) 2022 Your Company
 */

#include "lexer.h"
#include "token.h"
#include "double_linked_list.h"
// #include "parser.h"
// #include "executer.h"
// #include "builtins.h"
// #include "env.h"
// #include "utils.h"
// #include "signals.h"

int main(void)
{
	char *command = "cat file1 > file2 | ls -la /bin/tmp | echo \"$PATH help\"";
	t_lexer *lexer;
	t_token *token;
	t_dlinked_list *tokens;
	
	lexer = init_lexer(command);
	tokens = NULL;
	token = lexer_next_token(lexer);
	while (token->type != TOKEN_EOF)
	{
		ft_add_node_to_back(&tokens, ft_new_node(token));
		token = lexer_next_token(lexer);
	}
	t_dlinked_list *tokens_copy;
	tokens_copy = tokens;
	while (tokens_copy)
	{
		token = (t_token *)tokens_copy->content;
		printf("%s\n", token->value);
		tokens_copy = tokens_copy->next;
	}
	return (0);
}