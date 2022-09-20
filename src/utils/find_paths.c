/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 09:17:49 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/14 11:54:52 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*find_paths(char **env)
{
	while (*env && ft_strncmp("PATH", *env, 4))
		env++;
	if (*env)
		return (*env + 5);
	return (NULL);
}
