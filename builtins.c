/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:57:31 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/24 21:02:58 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path)
		printf ("%s\n", path);
    return ;
}

void	ft_cd(char	*path)
{
	DIR	*path_stream;
	path_stream = opendir(path);
	if (path_stream)
	{
		if (chdir(path))
			printf("Error on changing directory !\n");
		closedir(path_stream);
	}
	return ;
}

void	ft_echo(char *string, int option)
{
	if (string)
	{
		if (option)
			printf("%s", string);
		else
			printf("%s\n", string);
	}
	return ;
}

char	*ft_variable(char *var)
{
	int		i;
	char	*variable;

	i = 0;
	while (var[i] != '=')
		i++;
	variable = malloc(sizeof(char) * i + 1);
	if (!variable)
		return (NULL);
	i = 0;
	while (var[i] != '=')
	{
		variable[i] = var[i];
		i++;
	}
	variable[i] = '\0';
	return (variable);
}

char	*ft_value(char *var)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	while (var[i] != '=')
		i++;
	i++;
	value = malloc(sizeof(char) * (ft_strlen(var) - i) + 1);
	if (!value)
		return (NULL);
	j = 0;
	while (var[i])
	{
		value[j] = var[i];
		j++;
		i++;
	}
	value[j] = '\0';
	return (value);
}

t_list	*ft_lstnew(char *full_var)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->variable = ft_variable(full_var);
	node->value = ft_value(full_var);
	node->next = NULL;
	return (node);
}

void	fill_lst(t_list **head, char *full_var)
{
	t_list	*new;

	if (!*head)
		*head = ft_lstnew(full_var);
	else
	{
		new = ft_lstnew(full_var);
		ft_lstadd_back(head, new);
	}
}

t_list	*env_list(char **env)
{
	t_list	*head;
	int		i;

	head = NULL;
	i = 0;
	while (env[i])
	{
		fill_lst(&head, env[i]);
		i++;
	}
	return (head);
}

int	main(int ac, char **av, char ** env)
{
	t_list	*tmp;

	tmp = env_list(env);
	while (tmp->next)
	{
		printf("%s = %s\n", tmp->variable, tmp->value);
		tmp = tmp->next;
	}
	printf("%s = %s\n", tmp->variable, tmp->value);
	// ft_echo(NULL, 1);
	return (0);
}