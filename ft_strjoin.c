/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:35:43 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/09 04:12:45 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	joinup(int i, char const *s2, char *p, int j)
{
	while (s2[j])
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*p;
	int		i;
	size_t	s;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(sizeof(char) * s);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	i = joinup(i, s2, p, j);
	free((void *)s1);
	p[i] = '\0';
	return (p);
}
