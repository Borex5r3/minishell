#include "lexer.h"

t_lexer *init_lexer(char *src)
{
	t_lexer *lexer;

	lexer = (t_lexer*)malloc(sizeof(t_lexer));
	if (!lexer || !src)
		return (NULL);
	lexer->src = src;
	lexer->src_size = ft_strlen(src);
	lexer->i = 0;
	lexer->c = lexer->src[lexer->i];

	return (lexer);
}

void lexer_advance(t_lexer *lexer)
{
	if (lexer->i < lexer->src_size && lexer->c != '\0')
	{
		lexer->i++;
		lexer->c = lexer->src[lexer->i];
	}
}

void lexer_skip_whitespace(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t')
		lexer_advance(lexer);
}

t_token *lexer_next_token(t_lexer *lexer)
{
	t_token *token;

	lexer_skip_whitespace(lexer);
	if (lexer->c == '\0')
		return (init_token("", TOKEN_EOF));
	if (lexer->c == '>')
	{
		lexer_advance(lexer);
		if (lexer->c == '>')
		{
			lexer_advance(lexer);
			return (init_token(">>", TOKEN_DGREAT));
		}
		return (init_token(">", TOKEN_GREAT));
	}
	if (lexer->c == '<')
	{
		lexer_advance(lexer);
		if (lexer->c == '<')
		{
			lexer_advance(lexer);
			return (init_token("<<", TOKEN_DLESS));
		}
		return (init_token("<", TOKEN_LESS));
	}
	if (lexer->c == '|')
	{
		lexer_advance(lexer);
		if (lexer->c == '|')
		{
			lexer_advance(lexer);
			return (init_token("||", TOKEN_PIPE));
		}
		return (init_token("|", TOKEN_PIPE));
	}
	if (lexer->c == '(')
	{
		lexer_advance(lexer);
		return (init_token("(", TOKEN_LPAREN));
	}
	if (lexer->c == ')')
	{
		lexer_advance(lexer);
		return (init_token(")", TOKEN_RPAREN));
	}
	if (lexer->c == '\'')
	{
		lexer_advance(lexer);
		return (init_token("'", TOKEN_SQUOTE));
	}
	if (lexer->c == '"')
	{
		lexer_advance(lexer);
		return (init_token("\"", TOKEN_DQUOTE));
	}
	token = init_token("", TOKEN_TEXT);
	while (lexer->c != '\0' && lexer->c != '>' && lexer->c != '<' && lexer->c != '|' && lexer->c != '(' && lexer->c != ')' && lexer->c != '\'' && lexer->c != '"')
	{
		token->value = ft_strjoin(token->value, ft_strdup(&lexer->c));
		lexer_advance(lexer);
	}

	return (token);
}

