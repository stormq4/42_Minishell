/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 19:11:03 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/21 09:35:11 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_bool	mini_env(char **env, char *cmd)
{
	if (*cmd)
	{
		ft_putstr_fd("minishell: env: too many arguments\n", 2);
		g_error = 1;
		exit(g_error);
	}
	while (*env)
	{
		ft_putendl_fd(*env, 1);
		env++;
	}
	g_error = 0;
	exit(g_error);
	return (true);
}
