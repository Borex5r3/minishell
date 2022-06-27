/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:49:16 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/25 19:14:08 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_list	*my_env_list(char **env)
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

void	print_env(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		printf("%s = %s\n", tmp->variable, tmp->value);
		tmp = tmp->next;
	}
	printf("%s = %s\n", tmp->variable, tmp->value);
	return ;
}

int	main(int ac, char **av, char **env)
{
	t_list	*tmp;

	tmp = my_env_list(env);
	print_env(&tmp);
	printf("###################################################\n");
	sleep(3);
	ft_export(&tmp, "test=true");
	ft_export(&tmp, "test=false");
	print_env(&tmp);
	printf("###################################################\n");
	ft_unset(&tmp, "test");
	print_env(&tmp);
	return (0);
}