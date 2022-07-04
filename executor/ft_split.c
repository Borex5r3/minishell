/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:12:09 by adbaich           #+#    #+#             */
/*   Updated: 2022/03/20 16:23:08 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

static int	check(char const s, char c)
{
	if (s != c)
		return (1);
	return (0);
}

static int	nbs(char const *s, char c)
{
	int	i;
	int	nbs;
	int	j;

	nbs = 0;
	i = 0;
	while (s[i])
	{
		j = i;
		while (check(s[j], c) && s[j])
			j++;
		if (j > i)
		{
			i = j;
			nbs++;
			continue ;
		}
		i++;
	}
	return (nbs);
}

static char	*ft_strndup(char const *s, int i)
{
	char	*p;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	while (s[j] && j < i)
	{
		p[j] = s[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (nbs(s, c) + 1));
	if (!res)
		return (NULL);
	i = -1;
	k = 0;
	while (s[++i])
	{
		j = i;
		while (check(s[j], c) && s[j])
			j++;
		if (j > i)
		{
			res[k++] = ft_strndup(&s[i], j - i);
			i = j - 1;
		}
	}
	res[k] = 0;
	return (res);
}
