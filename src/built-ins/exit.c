/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 18:55:10 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/20 09:44:03 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	print_first_error_arg(char *cmd)
{
	while (*cmd && *cmd != ' ')
	{
		ft_putchar_fd(*cmd, 2);
		cmd++;
	}
	ft_putstr_fd(": ", 2);
}

static char	*check_arg_is_digit(char *cmd, char *str)
{
	while (*cmd && *cmd != ' ')
	{
		if (!ft_isdigit(*cmd))
		{
			g_error = 255;
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: ", 2);
			print_first_error_arg(str);
			ft_putstr_fd("numeric argument required\n", 2);
			exit(g_error);
		}
		cmd++;
	}
	return (cmd);
}

t_bool	single_cmd_exit(char *cmd)
{
	char	*str;

	if (!*cmd)
	{
		ft_putstr_fd("exit\n", 2);
		exit(g_error);
	}
	cmd++;
	str = cmd;
	cmd = check_arg_is_digit(cmd, str);
	if (*cmd == 0)
	{
		g_error = ft_atoi(str) % 256;
		ft_putstr_fd("exit\n", 2);
		exit(g_error);
	}
	ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	g_error = 1;
	return (true);
}

t_bool	multiple_cmd_exit(char *cmd)
{
	char	*str;

	if (!*cmd)
		exit(g_error);
	cmd++;
	str = cmd;
	cmd = check_arg_is_digit(cmd, str);
	if (*cmd == 0)
	{
		g_error = ft_atoi(str) % 256;
		exit(g_error);
	}
	ft_putstr_fd("minishell: exit: too many arguments\n", 2);
	g_error = 1;
	exit(g_error);
	return (true);
}
