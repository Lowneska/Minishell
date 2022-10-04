/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:05:09 by skhali            #+#    #+#             */
/*   Updated: 2022/10/04 17:22:29 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int ln_checker(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-')
    {
        i++;
        while (str[i])
        {
            if (str[i] && str[i] != 'n')
                return (0);
            i++;
        }
    }
    else
        return (0);
    return (1);
}
//afficher les variabloes d'env
int    built_in_echo(char **cmds)
{
    int i;
    int ln;

    i = 1;
    while (cmds[i])
    {
        if (ln_checker(cmds[i]))
        {
            ln = 1;
            i++;
        }
        else
            break ;
    }
    while (cmds[i])
    {
        ft_putstr_fd(cmds[i], 1);
        if (cmds[i + 1])
            write(1, " ", 1);
        i++;
    }
    if (!ln)
        write(1, "\n", 1);
    return (0);
}