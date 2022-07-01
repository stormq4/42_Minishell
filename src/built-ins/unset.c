/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:51:35 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/25 00:41:09 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

static int	envlen(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int	unset_var(char *var, char ***env)
{
	int		i;
	int		j;
	int		envvarlen;
	char	**nenv;

	nenv = pmalloc(sizeof(char *) * (envlen((*env))));
	i = -1;
	j = 0;
	while ((*env)[++i])
	{
		envvarlen = ft_strlen((*env)[i]) - ft_strlen(ft_strchr((*env)[i], '='));
		if ((ft_strncmp((*env)[i], var, ft_strlen(var)) == 0) && \
		(int)ft_strlen(var) == envvarlen)
		{
			free((*env)[i]);
			continue ;
		}
		nenv[j] = (*env)[i];
		j++;
	}
	free((*env));
	(*env) = nenv;
	return (EXIT_SUCCESS);
}

t_bool	mini_unset(char *cmdline, char ***env)
{
	char	**split_args;
	char	*args;
	int		i;

	args = cmdline;
	if (!args || *args == '-')
	{
		g_error = 1;
		return (true);
	}
	split_args = ft_split(args, ' ');
	i = -1;
	while (split_args[++i])
		unset_var(split_args[i], env);
	if (split_args)
		free_split_arr(split_args);
	g_error = 0;
	return (true);
}

t_bool	mult_unset(char *cmd_line, char ***env)
{
	mini_unset(cmd_line, env);
	exit(g_error);
	return (true);
}
