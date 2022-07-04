/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:03:49 by adbaich           #+#    #+#             */
/*   Updated: 2022/06/07 01:35:42 by adbaich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_pwd(char **env)
{
    int     i;
    int     j;
    int     x;
    char    *pwd;

    i = 0;
    while(ft_strncmp(env[i], "PWD=", 4))
        i++;
    pwd = malloc(sizeof(char) * (ft_strlen(env[i]) - 4));
    if (!pwd)
        return ;
    j = 0;
    while (env[i][j] != '/')
        j++;
    x = 0;
    while (env[i][j])
    {
        pwd[x] = env[i][j];
        j++;
        x++;
    }
    pwd[x] = '\0';
    printf("%s\n", pwd);
    free(pwd);
}

int main(int ac, char **av, char **env)
{
    ft_pwd(env);
    return (0);
}