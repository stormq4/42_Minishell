/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust_location.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 15:41:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/07/01 14:24:03 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	adjust_location(char **env)
{
	char	*location;

	while (*env && ft_strncmp("_=", *env, 2))
		env++;
	location = *env;
	if (!location)
		return ;
	free(location);
	*env = ft_strjoin("_=", "./minishell");
	ft_check_malloc(*env);
}
