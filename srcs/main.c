/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:05:16 by skhali            #+#    #+#             */
/*   Updated: 2022/10/04 23:57:33 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoinms(char *s1, char *s2)
{	
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = calloc(sizeof(char), (len) + 1);
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

t_env	*ft_lstnew(char  *value)
{
	t_env *cell;

    cell = (t_env *)malloc(sizeof(t_env));
	if (!cell)
		return (NULL);
	cell->val= value;
	cell->next = NULL;
	return (cell);
}

void	ft_lstadd_back(t_env **alst, t_env *new)
{
	t_env *copy;

	if (!alst)
		return ;
	copy = *alst;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	if (copy)
	{
		while (copy->next)
			copy = copy->next;
		copy->next = new;
	}
}
t_env *create_env(char **env)
{
    char buf[PATH_MAX + 1];
    char *pwd;
    t_env *tmp;
    tmp = NULL;
	int i;

    getcwd(buf, sizeof(buf));
    pwd = ft_strjoinms("PWD=", buf);
    if (!env[0])
    {
        ft_lstadd_back(&tmp, ft_lstnew("SHLVL=1"));
        ft_lstadd_back(&tmp, ft_lstnew(pwd));
		ft_lstadd_back(&tmp, ft_lstnew("_=./minishell"));
        return (tmp);
    }
	i = -1;
	while (env[++i])
		ft_lstadd_back(&tmp, ft_lstnew(env[i]));
    return (tmp);
}


int main(int argc, char **argv, char **env)
{
    t_env *envp;
	t_minishell *ms;
    (void) argc;
    (void)argv;
	int i;
	
	ms = malloc(sizeof(t_minishell));
	ms->cmds = malloc(sizeof(t_command));
    ms->env = create_env(env);
	ms->cmds->cmd = ++argv;
	i = 0;
	while(ms->cmds->cmd[i])
	{
        printf("%s\n", ms->cmds->cmd[i]);
        i++;
    }
	printf(("--------------------------\n"));
	i = builtins(ms, ms->cmds->cmd);
	envp = ms->env;
	while(envp)
    {
        printf("%s\n", envp->val);
        envp = envp->next;
    }
	printf(("--------------------------\n"));
	printf("Valeur de retour : %d\n", i);

	
	free(ms);
}