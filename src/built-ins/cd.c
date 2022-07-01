/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 09:35:56 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/07/01 13:18:33 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/**
 * @brief Updates the oldpwd in env; If oldpwd is not yet set
 * it will add it to the env, otherwise it will update its value
 * 
 * @param env 
 * @return if getcwd / malloc fail return false on succes return true
 */
t_bool	update_oldpwd(char ***env)
{
	char	cdirectory[PATH_MAX];
	char	*oldpwd;
	char	**split;

	if (getcwd(cdirectory, PATH_MAX) == NULL)
		return (false);
	oldpwd = ft_strjoin("OLDPWD=", cdirectory);
	if (!oldpwd)
		return (false);
	split_var(oldpwd, &split);
	export_var(oldpwd, env, split);
	free_split_arr(split);
	return (true);
}

t_bool	go_to_home(char ***env)
{
	char	*path;

	update_oldpwd(env);
	path = find_env_var("$HOME", (*env));
	if (!path)
	{
		ft_putstr_fd("minishell: cd: HOME not set", 2);
		g_error = 1;
		return (false);
	}
	chdir(path);
	return (true);
}

t_bool	go_to_oldpwd(char ***env)
{
	char	*path;

	path = find_env_var("$OLDPWD", (*env));
	if (!path)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		g_error = 1;
		return (false);
	}
	update_oldpwd(env);
	chdir(path);
	return (true);
}

t_bool	mini_cd(char *args, char ***env)
{
	int	err;

	if (!(*args))
		return (go_to_home(env));
	else if (ft_strlen(args) == 2 && ft_strncmp(args, " -", 2) == 0)
		return (go_to_oldpwd(env));
	else
	{
		args++;
		update_oldpwd(env);
		err = chdir(args);
		if (err < 0)
			err *= -1;
		if (err != 0)
			perror(args);
	}
	return (true);
}

t_bool	mult_cd(char *cmd, char ***env)
{
	mini_cd(cmd, env);
	exit(g_error);
	return (true);
}
