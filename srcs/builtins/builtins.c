#include "../../include/minishell.h"

int	builtins(t_minishell *ms, char **cmd)
{
	if (!cmd[0])
		return (-1);
	if (!ft_strncmp(cmd[0], "echo", sizeof(cmd[0])))
		return (built_in_echo(cmd));
	else if (!ft_strncmp(cmd[0], "pwd", sizeof(cmd[0])))
		return (built_in_pwd(ms->env, cmd));
	else if (!ft_strncmp(cmd[0], "env", sizeof(cmd[0])))
		return (built_in_env(ms->env, cmd));
	else if (!ft_strncmp(cmd[0], "cd", 2))
		return (built_in_cd(ms->env, cmd));
	else if (!ft_strncmp(cmd[0], "export", sizeof(cmd[0])))
		return (built_in_export(ms->env, cmd));
	else if (!ft_strncmp(cmd[0], "unset", sizeof(cmd[0])))
		return (built_in_unset(&(ms->env), cmd));
	return (-1);
}