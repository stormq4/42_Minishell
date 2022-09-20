/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:51:35 by gpirro            #+#    #+#             */
/*   Updated: 2022/07/03 12:02:56 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

static int	err_in_export(char *args, char ***env, char *cmdline)
{
	if (ft_strlen(args) < 1)
	{
		print_export((*env));
		return (true);
	}
	if (!ft_strchr(cmdline, '=') || *args == '-')
	{
		g_error = 0;
		return (true);
	}
	return (false);
}

t_bool	mini_export(char *cmdline, char ***env)
{
	char	**split_args;
	char	**split;
	char	*args;
	int		i;

	args = cmdline;
	if (err_in_export(args, env, cmdline))
		return (true);
	split_args = ft_split(args, ' ');
	i = -1;
	while (split_args[++i])
	{
		if (ft_strchr(split_args[i], '=') && is_valid_identifier(split_args[i]))
		{
			split_var(split_args[i], &split);
			export_var(split_args[i], env, split);
			free_split_arr(split);
		}
	}
	if (split_args)
		free(split_args);
	g_error = 0;
	return (true);
}
