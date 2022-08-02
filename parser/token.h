/*
 * Filename: /home/guts/Desktop/minishell/token.h
 * Path: /home/guts/Desktop/minishell
 * Created Date: Monday, August 1st 2022, 3:26:49 pm
 * Author: Hamza
 * 
 * Copyright (c) 2022 Your Company
 */
#ifndef TOKEN_H
# define TOKEN_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef enum e_type
{
	TOKEN_PIPE,
	TOKEN_TEXT,
	TOKEN_RPAREN,
	TOKEN_LPAREN,
	TOKEN_GREAT,
	TOKEN_LESS,
	TOKEN_DGREAT,
	TOKEN_DLESS,
	TOKEN_SQUOTE,
	TOKEN_DQUOTE,
	TOKEN_EOF
} t_type;

typedef struct s_token
{
	char *value;
	t_type type;
} t_token;

t_token *init_token(char *value, t_type type);

#endif