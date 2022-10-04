/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:05:12 by skhali            #+#    #+#             */
/*   Updated: 2022/10/04 18:02:39 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
//si le temps : modifier la valeur de _ en env
int    built_in_env(t_env *env, char **cmd)
{
    //display error si un argument est entré
    if (cmd[1])
        return (ft_putstr_fd("env: ", 2), write(2, cmd[1],
            ft_strlen(cmd[1])), ft_putstr_fd(": no such file or directory.\n", 2), 127);
    while(env)
    {
        printf("%s\n", env->val);
        env = env->next;
    }
    return (0);
}