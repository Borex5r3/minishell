/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:41:34 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/20 20:58:48 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe(char **env)
{
	int	fd[2];
	int	id1;
	int	id2;

	pipe(fd);
	id1 = fork();
	if (id1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execute_cmd(get_paths(env), "cat", "/dev/random", env);
	}
	else
	{
		id2 = fork();
		if (id2 == 0)
		{
			close(fd[1]);
			dup2(fd[0], 0);
			execute_cmd(get_paths(env), "ls", NULL, env);
		}
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return;
}

void	multiple_pipes(int	number_of_cmd, char **env)
{
	int	fd[number_of_cmd][2];
	int	i;
	int	j;
	int id;

	i = 0;
	while (i < number_of_cmd)
	{
		pipe(fd[i]);
		i++;
	}
	i = 0;
	while (i < number_of_cmd)
	{
		id = fork();
		if (id == 0)
		{
			if (i != 0)
			{
				if (dup2(fd[i][0], 0) == -1)
					printf("Error on duplicate fd\n");
			}
			if (i != number_of_cmd - 1)
			{
				if (dup2(fd[i + 1][1], 1) == -1)
					printf("Error on duplicate fd\n");
			}
			j = i;
			while (j < number_of_cmd)
			{
				if (close(fd[j][0]) == -1)
					printf("Error on close fd\n");
				if (close(fd[j][1]) == -1)
					printf("Error on close fd\n");
				j++;
			}
			if (i == 0)
				execute_cmd(get_paths(env), "cat", "/dev/random", env);
			else if (i == 1)
				execute_cmd(get_paths(env), "sleep", "4", env);
			else if (i == 2)
				execute_cmd(get_paths(env), "ls", "-l", env);
		}
		i++;
	}

	i = 0;
	while (i < number_of_cmd)
	{
		if (close(fd[i][0]) == -1)
			printf("Error on close fd\n");
		if (close(fd[i][1]) == -1)
			printf("Error on close fd\n");
		i++;
	}
	i = 0;
	while (i < number_of_cmd)
	{
		wait(NULL);
		i++;
		// printf("Done !\n");
	}
}

int	main(int ac, char **av, char ** env)
{
	// ft_pipe(env);
	multiple_pipes(3, env);
	return (0);
}