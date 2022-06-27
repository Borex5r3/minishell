/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:09:41 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/25 19:13:20 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct s_list
{
    char	*variable;
    char	*value;
	struct s_list	*next;
}	t_list;
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	**get_paths(char **env);
void	execute_cmd(char **paths, char *cmd, char *arg_cmd, char **env);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	fill_lst(t_list **head, char *full_var);
void	ft_export(t_list **head, char *full_var);
char	*ft_variable(char *var);
char	*ft_value(char *var);
void	ft_unset(t_list **head, char *var_name);
size_t	max_len(char *first_str, char *second_str);

#endif