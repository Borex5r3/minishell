/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:34:09 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/26 16:15:21 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

char	*rm_path_name(char *path)
{
    char	*new_path;
    int		i;
    int		y;

    new_path = malloc(sizeof(char) * (ft_strlen(path) - ft_strlen("PATH=") + 1));
    if (!new_path)
        return (NULL);
    i = 0;
    y = 5;
    while (path[y])
    {
        new_path[i] = path[y];
        y++;
        i++;
    }
    new_path[i] = '\0';
    return (new_path);
}

t_list	*find_path(t_list **head)
{
    t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (!ft_strncmp("PATH", tmp->variable, max_len("PATH", tmp->variable)))
			break;
		tmp = tmp->next;
	}
    return (tmp);
}

char	**fill_new_paths(char **paths, char **new_paths, char *cmd)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (paths[i])
	{
		new_paths[i] = ft_strjoin(new_paths[i], paths[i]);
		new_paths[i] = ft_strjoin(new_paths[i], "/");
		new_paths[i] = ft_strjoin(new_paths[i], cmd);
		i++;
	}
	new_paths[i] = 0;
	return (new_paths);
}

char	**modify_paths(t_list *path, char *cmd)
{
	char	**new_paths;
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(path->value, ':');
	while (paths[i])
		i++;
	new_paths = malloc(sizeof(char *) * (i + 1));
	if (!new_paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		new_paths[i] = malloc(sizeof(char) * 1);
		if (!new_paths[i])
			return (NULL);
		new_paths[i][0] = '\0';
		i++;
	}
	new_paths = fill_new_paths(paths, new_paths, cmd);
	return (new_paths);
}

void	execute_cmd(t_list **head, char *cmd, char *arg_cmd, char **env)
{
    int		i;
    char	**new_paths;
	char	*args[] = {cmd, arg_cmd, NULL};

    i = 0;
	new_paths = modify_paths(find_path(head), cmd);
	while (access(new_paths[i], F_OK) == -1)
		i++;
	execve(new_paths[i], args, env);
	exit(0);
}
