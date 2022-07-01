/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 13:11:05 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/07/01 13:29:08 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	split_var(char *var, char ***split)
{
	int		blen;
	int		alen;
	int		i;

	(*split) = (char **)pmalloc(sizeof(char *) * 3);
	blen = ft_strchr(var, '=') - var + 1;
	alen = ft_strlen(ft_strchr(var, '=')) - 1;
	(*split)[0] = (char *)pmalloc(sizeof(char) * blen + 1);
	(*split)[1] = (char *)pmalloc(sizeof(char) * alen + 1);
	(*split)[2] = NULL;
	i = -1;
	while (++i < blen)
		(*split)[0][i] = var[i];
	i = -1;
	while (++i < alen)
		(*split)[1][i] = var[i + blen];
	i = -1;
	return (EXIT_SUCCESS);
}

static int	var_already_exists(char *var, char ***env, char **split)
{
	int		i;
	char	*tmpstr;

	i = -1;
	while ((*env)[++i])
	{
		if (!ft_strncmp(split[0], (*env)[i], ft_strlen(split[0])))
		{
			tmpstr = (*env)[i];
			(*env)[i] = var;
			free(tmpstr);
			return (true);
		}
	}
	return (false);
}

/**
 * @brief pass var as the complete var that should be in env so x=y 
 * (Should be malloced do not free)
 * 
 * @param var 
 * @param env 
 * @param split 
 */
void	export_var(char *var, char ***env, char **split)
{
	char	**nenv;
	char	**tmp;
	int		len;
	int		i;

	if (var_already_exists(var, env, split))
		return ;
	tmp = *env;
	len = 0;
	while ((*env)[len])
		len++;
	nenv = pmalloc(sizeof(char *) * (len + 2));
	i = -1;
	while ((*env)[++i])
		nenv[i] = (*env)[i];
	nenv[i] = var;
	nenv[i + 1] = NULL;
	*env = nenv;
	free(tmp);
}
