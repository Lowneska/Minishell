#include "../../include/minishell.h"
 
 //SI PWD existe deja -> renvois son contenu
 //Si il est unset -> renvois el dossier dans Trash
 //Parcourir env et chercher PWD
 //si il existe afficher son contenu
 //sinon, afficher le resultat de getcwd



char     *var_checker(t_env *env, char *str)
{
    while(env)
    {
        if ((!ft_strncmp(env->val, str, ft_strlen(str)))
            && (env->val[ft_strlen(str)] == '='))
            return (env->val);
        env = env->next;
    }
    return (NULL);
}
int    built_in_pwd(t_env *env, char **cmd)
{
    char buf[PATH_MAX + 1];
    char *pwd;
    char *str;
    
    if (cmd[1] && !ft_strncmp(cmd[1], "-", 1))
        return (ft_putstr_fd("pwd: ", 2), write(2, cmd[1],
            ft_strlen(cmd[1])), ft_putstr_fd(": invalid option\n", 2), 1);
    if ((str = var_checker(env, "PWD")))
    {
        str = get_content(str);
        return (printf("%s\n", ++str), 0);
    }
    pwd = getcwd(buf, sizeof(buf));
    if (pwd)
        return (ft_putstr_fd("pwd : the current directory cannot be read\n", 2), 1);
    printf("%s\n", buf);
    return (0);
}