 #include "list.h"

static void	ctrl_c_heredoc(int sig)
{
	(void)sig;
	close(0);
	printf("\n");
	g_status = -42;
}

void	ctrl_c(int sig)
{
	(void)sig;
	g_status = 130;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_signals_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c_heredoc);	
}

void	handle_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c);
}

void	reset_signals(t_minishell *data)
{
	(void)data;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	ctrl_back_slash(int signum)
{
	(void)signum;
	rl_on_new_line();
	rl_replace_line("", 0);
	g_status = 131;
}

void	ctrl_c_exec(int signum)
{
	(void)signum;
	ft_putchar_fd('\n', 2);
	g_status = 130;
}

void	handle_signals_exec(t_minishell *data)
{
	(void)data;
	signal(SIGINT, ctrl_c_exec);
	signal(SIGQUIT, ctrl_back_slash);
}