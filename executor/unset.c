/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:30:22 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/25 19:13:28 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_list **head, char *var_name)
{
	t_list	*tmp;
	t_list	*before_tmp;

	tmp = *head;
	while (tmp)
	{
		if (!ft_strncmp(var_name, tmp->variable, max_len(var_name, tmp->variable)))
			break;
		before_tmp = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		before_tmp->next = tmp->next;
		free(tmp->variable);
		free(tmp->value);
		free(tmp);
	}
	return ;
}
