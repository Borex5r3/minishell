/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:44:19 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/23 16:45:37 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_here_doc(char *input_hrdc, int *fd)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		printf("%s\n", input_hrdc);
		exit(0);
	}
	wait(NULL);
	if (id != 0)
		kill(id, SIGKILL);
	return ;
}

void	output_here_doc(int *fd, char **env)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		execute_cmd(get_paths(env), "ls", NULL, env);
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	return ;
}

void	here_doc(char **env)
{
	char	*p;
	int		fd[2];

	pipe(fd);
	printf("Done !\n");
	p = readline("> ");
	input_here_doc(p, fd);
	while (p)
	{
		p = readline("> ");
		if (p)
			input_here_doc(p, fd);
	}
	printf("\n");
	output_here_doc(fd, env);
}

int	main(int ac, char **av, char **env)
{
	printf("%s\n",getcwd(NULL, 0));
	return (0);
}
