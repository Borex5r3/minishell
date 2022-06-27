/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:24:55 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/20 19:44:39 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_output(char **env, char *file_name)
{
	int	fd;
	int	id;

	fd = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(fd, 1);
	id = fork();
	if (id == 0)
		execute_cmd(get_paths(env), "cat te", NULL, env);
	return ;
}

void	redirect_output_append(char **env)
{
	int	fd;
	int	id;

	fd = open("test.txt", O_CREAT | O_RDWR | O_APPEND, 0644);
	dup2(fd, 1);
	id = fork();
	if (id == 0)
		execute_cmd(get_paths(env), "ls", NULL, env);
	return ;
}

void	redirect_input(char **env)
{
	int	fd;
	int	id;

	fd = open("test.txt", O_RDONLY , 0644);
	dup2(fd, 0);
	id = fork();
	if (id == 0)
		execute_cmd(get_paths(env), "wc", NULL, env);
	return ;
}

int	main(int ac, char **av, char **env)
{
    redirect_output(env, "test.txt");
	return (0);
}