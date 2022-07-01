/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:12:25 by sde-quai          #+#    #+#             */
/*   Updated: 2022/06/26 21:13:51 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**malloc_env(char **env)
{
	int		size;
	char	**new_env;

	size = 0;
	while (env[size])
		size++;
	new_env = malloc(sizeof(char *) * (size + 1));
	ft_check_malloc(new_env);
	size = 0;
	while (env[size])
	{
		new_env[size] = ft_strdup(env[size]);
		size++;
	}
	new_env[size] = NULL;
	return (new_env);
}
