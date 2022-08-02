/*
 * Filename: /home/guts/Desktop/minishell/token.c
 * Path: /home/guts/Desktop/minishell
 * Created Date: Monday, August 1st 2022, 3:44:05 pm
 * Author: Hamza
 * 
 * Copyright (c) 2022 Your Company
 */

#include "token.h"

t_token *init_token(char *value, t_type type)
{
	t_token *token;

	token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->value = value;
	token->type = type;
	return (token);
}