#include "list.h"

int	check_exit_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i])
		return (1);
	return (0);
}

int	built_in_exit(char **cmd, int child)
{
	unsigned char	code;
    //vérifier si les args sont numeric
    //vérifier si il y a plusieurs arguemnts
    //vérifier si une seule commande

	if (!child)
		ft_putstr_fd("exit\n", 1);
	if (size_chartab(cmd) == 1)
		return (exit(g_status), g_status);
	if (check_exit_numeric(cmd[1]))
			return (ft_putstr_fd("exit: numeric argument required\n", 2),
				exit(2), 2);
	if (size_chartab(cmd) > 2)
		return (ft_putstr_fd("exit: too many arguments\n", 2), 1);
	code = ft_atoi(cmd[1]);
	return (exit((int)code), 0);
}