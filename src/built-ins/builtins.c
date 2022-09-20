/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/13 14:36:57 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/15 14:34:05 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

t_bool	check_clean_builtin(char *str, int size)
{
	int	i;

	i = 0;
	if (!*str)
		return (true);
	while (*str)
	{
		if (i == size && *str != ' ')
			return (false);
		str++;
		i++;
	}
	return (true);
}

t_bool	all_builtins(char *cmd, char ***envp)
{
	if (!cmd || !envp)
		return (false);
	if (!ft_strncmp(cmd, "env", 3) && check_clean_builtin(cmd, 3))
		return (mini_env(*envp, cmd + 3));
	else if (!ft_strncmp(cmd, "exit", 4) && check_clean_builtin(cmd, 4))
		return (multiple_cmd_exit(cmd + 4));
	else if (!ft_strncmp(cmd, "echo", 4) && check_clean_builtin(cmd, 4))
		return (mini_echo(cmd));
	else if (!ft_strncmp(cmd, "pwd", 3) && check_clean_builtin(cmd, 3))
		return (mini_pwd());
	else if (!ft_strncmp(cmd, "cd", 2) && check_clean_builtin(cmd, 2))
		return (mult_cd(cmd + 2, envp));
	else if (!ft_strncmp(cmd, "export", 6) && check_clean_builtin(cmd, 6))
		return (mult_export(cmd + 6, envp));
	else if (!ft_strncmp(cmd, "unset", 5) && check_clean_builtin(cmd, 5))
		return (mult_unset(cmd + 5, envp));
	return (false);
}

t_bool	single_cmd_builtins(char *cmd, char ***envp)
{
	if (!ft_strncmp(cmd, "exit", 4) && check_clean_builtin(cmd, 4))
		return (single_cmd_exit(cmd + 4));
	else if (!ft_strncmp(cmd, "cd", 2) && check_clean_builtin(cmd, 2))
		return (mini_cd(cmd + 2, envp));
	else if (!ft_strncmp(cmd, "export", 6) && check_clean_builtin(cmd, 6))
		return (mini_export(cmd + 6, envp));
	else if (!ft_strncmp(cmd, "unset", 5) && check_clean_builtin(cmd, 5))
		return (mini_unset(cmd + 5, envp));
	return (false);
}

t_bool	single_cmd_builtins_check(char *cmd)
{
	if (!ft_strncmp(cmd, "exit", 4) && check_clean_builtin(cmd, 4))
		return (true);
	else if (!ft_strncmp(cmd, "cd", 2) && check_clean_builtin(cmd, 2))
		return (true);
	else if (!ft_strncmp(cmd, "export", 6) && check_clean_builtin(cmd, 6))
		return (true);
	else if (!ft_strncmp(cmd, "unset", 5) && check_clean_builtin(cmd, 5))
		return (true);
	return (false);
}
