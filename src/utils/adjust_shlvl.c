/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_shlvl.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 10:24:41 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/07/01 14:23:30 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool	shlvl_exists(char **env)
{
	while (*env)
	{
		if (ft_strncmp("SHLVL", *env, 5) == 0)
			return (true);
		env++;
	}
	return (false);
}

char	*find_shlvl(char **env)
{
	while (*env && ft_strncmp("SHLVL", *env, 5))
		env++;
	if (*env)
		return (*env + 6);
	return (NULL);
}

void	adjust_shlvl(char **env, t_bool increment)
{
	char	*lvl;
	int		level;
	char	*newlvl;
	char	**split;

	if (!shlvl_exists(env))
	{
		split_var("SHLVL=1", &split);
		export_var("SHLVL=1", &env, split);
		return ;
	}
	lvl = find_shlvl(env);
	level = ft_atoi(lvl);
	if (increment == true)
		level++;
	else
		level--;
	newlvl = ft_itoa(level);
	*lvl = *newlvl;
	if (level >= 10)
	{
		*(lvl + 1) = *(newlvl + 1);
		*(lvl + 2) = 0;
	}
	free(newlvl);
}
