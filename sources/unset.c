/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:20:22 by skhali            #+#    #+#             */
/*   Updated: 2022/10/11 14:50:41 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "list.h"
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

t_env    *var_getter(t_env *env, char *str)
{
    while(env)
    {
        if ((!ft_strncmp(env->val, str, ft_strlen(str)))
            && (env->val[ft_strlen(str)] == '='))
            return (env);
        env = env->next;
    }
    return (NULL);
}

void	ft_del_lst_el(t_env **list, t_env *to_delete)
{
	t_env	*tmp;

	if (!list || !*list || !to_delete)
		return ;
	if (*list == to_delete)
	{
		tmp = *list;
		*list = (*list)->next;
		tmp->val = NULL;
		free(tmp);
		return ;
	}
	tmp = *list;
	while (tmp->next && tmp->next != to_delete)
		tmp = tmp->next;
	if (tmp->next)
	{
		tmp->next = tmp->next->next;
		return ;
	}
}

int built_in_unset(t_env **env, char **cmd)
{
    int i;

    i = 0;
    while (cmd[++i])
    {
        if (var_checker(*env, cmd[i]))
            ft_del_lst_el(env, var_getter(*env, cmd[i]));     
    }
	
    return (0);
}