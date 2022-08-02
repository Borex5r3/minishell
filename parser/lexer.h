/*
 * Filename: /home/guts/Desktop/minishell/lexer.h
 * Path: /home/guts/Desktop/minishell
 * Created Date: Monday, August 1st 2022, 3:48:07 pm
 * Author: Hamza
 * 
 * Copyright (c) 2022 Your Company
 */

#ifndef LEXER_H
# define LEXER_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "token.h"
# include "utils.h"

typedef struct s_lexer
{
	char *src;
	size_t src_size;
	char c;
	unsigned int i;
} t_lexer;

t_lexer *init_lexer(char *src);
void lexer_advance(t_lexer * lexer);
void lexer_skip_whitespace(t_lexer *lexer);

t_token *lexer_next_token(t_lexer *lexer);

#endif