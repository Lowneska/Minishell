/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:05:18 by skhali            #+#    #+#             */
/*   Updated: 2022/10/04 23:53:08 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int size_chartab(char **cmd)
{ 
    int i;

    i = 0;
    while (cmd[i])
        i++;
    return (i);
}
char	*ft_strappend(char *str, char *add, int size)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!add)
		return (str);
	while (str[i])
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (size + i + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	while (j < size)
	{
		res[i + j] = add[j];
		j++;
	}
	free(str);
	res[i + j] = '\0';
	return (res);
}

char *get_content(char *env)
{
    char *content;
    
    content = ft_strnstr(env, "=", ft_strlen(env));
    return (content);
}
int   built_in_cd_p2(t_env *env, char *cmd)
{
    char *str;
    char buf[PATH_MAX + 1];

    if (!var_checker(env, "PWD"))
    {
        built_in_export_p2(env, "OLDPWD=");
    }
    else
        {
            str = getcwd(buf, sizeof(buf));
            str = ft_strjoinms("OLDPWD=", str);
            built_in_export_p2(env, str);
            free(str);
        }
    if (chdir(cmd) == -1)
        return (ft_putstr_fd("cd: ", 2), write(2, cmd,
            ft_strlen(cmd)), ft_putstr_fd(": no such file or directory.\n", 2), 1);
    str = ft_strjoinms("PWD=", getcwd(buf, sizeof(buf)));
    built_in_export_p2(env, str);
    return (0);
}
int   built_in_cd(t_env *env, char **cmd)
{
    char *str;
    char *tmp;

    if (size_chartab(cmd) == 1)
    {
        str = ft_strdup(var_checker(env, "HOME"));
        if (!str)
            return (ft_putstr_fd("cd: HOME not set\n", 2), 1);
        else
        {
            tmp = get_content(str);
            tmp++;
        }
    }
    else if (size_chartab(cmd) > 2)
        return (ft_putstr_fd("cd: too many arguments\n", 2), 1);
    else
        tmp = cmd[1];

    built_in_cd_p2(env, tmp);
    return (0);
}