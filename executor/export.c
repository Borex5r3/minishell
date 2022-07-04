/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:06:09 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/25 17:55:24 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	max_len(char *first_str, char *second_str)
{
	size_t	fst_size;
	size_t	scd_size;

	fst_size = ft_strlen(first_str);
	scd_size = ft_strlen(second_str);
	if (fst_size > scd_size)
		return (fst_size);
	return (scd_size);
}

void	ft_export(t_list **head, char *full_var)
{
	t_list	*tmp;
	char	*var_name;
	int		modify;

	tmp = *head;
	modify = 0;
	var_name = ft_variable(full_var);
	while (tmp)
	{
		if (!ft_strncmp(var_name, tmp->variable, max_len(var_name, tmp->variable)))
		{
			modify = 1;
			break;
		}
		tmp = tmp->next;
	}
	if (modify)
	{
		free(tmp->value);
		tmp->value = ft_value(full_var);
	}
	else
		fill_lst(head, full_var);
	return ;
}