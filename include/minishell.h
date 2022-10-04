#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <linux/limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

typedef struct s_env
{
    char *val;
    struct s_env *next;  
}   t_env;

typedef struct s_command
{
    char **cmd;
    char *type;
    struct s_command *next;
} t_command;

typedef struct s_minishell
{
    t_env *env;
    t_command *cmds;
    char **path;
} t_minishell;

int     get_var_length(char *env);
char    *var_checker(t_env *env, char *str);
int     built_in_pwd(t_env *env, char **cmd);
int     built_in_env(t_env *env, char **cmd);
int     built_in_cd(t_env *env, char **cmd);
int     built_in_export(t_env *env, char **cmd);
int     built_in_unset(t_env **env, char **cmd);
int     built_in_echo(char **cmds);
int     builtins(t_minishell *ms, char **cmd);

size_t	ft_strlen(const char *s);
char	*ft_strjoinms(char *s1, char *s2);
t_env	*ft_lstnew(char  *value);
void	ft_lstadd_back(t_env **alst, t_env *new);
t_env *create_env(char **env);
int built_in_export_p2(t_env *env, char *cmd);

int	ft_strcmp(const char *s1, const char *s2);
char *get_content(char *env);
#endif
