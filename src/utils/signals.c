/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:12:15 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/20 10:28:12 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief signal is activated before a heredoc
 * 
 * @param sig 
 */
void	signal_ctrl_heredoc(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 1);
	g_error = 1;
	exit(errno);
}

/**
 * @brief ctrl-C signal is activated before the readline function
 * and redisplays the readline
 * 
 * @param sig 
 */
void	signal_ctrl_c(int sig)
{
	(void)sig;
	ft_putstr_fd("\nminishell> ", 1);
	g_error = 1;
	rl_on_new_line();
	rl_redisplay();
	signal(SIGQUIT, SIG_IGN);
}

/**
 * @brief quit signal is only activated in a running process
 * 
 * @param sig 
 */
void	signal_quit(int sig)
{
	ft_putstr_fd("Quit: ", 2);
	ft_putnbr_fd(sig, 2);
	ft_putstr_fd("\n", 2);
	g_error = 131;
}

/**
 * @brief if NULL is inputted to the command line
 * through ctrl-D then the program is quited
 * 
 * @param str 
 * @return t_bool 
 */
t_bool	signal_ctrl_d(char *str, char **env)
{
	if (str)
		return (false);
	ft_putstr_fd("exit\n", 1);
	if (shlvl_exists(env))
		adjust_shlvl(env, false);
	exit(g_error);
	return (true);
}

/**
 * @brief checks if the command_line is empty
 * 
 * @param str commandline
 * @return t_bool if empty
 */
t_bool	check_space_string(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (true);
		str++;
	}
	return (false);
}
