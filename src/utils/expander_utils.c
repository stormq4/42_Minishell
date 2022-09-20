/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:31:57 by gpirro            #+#    #+#             */
/*   Updated: 2022/09/16 17:55:44 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

/**
 * @brief protected malloc, Mallocs size into void *
 * if malloc fails exit with malloc failure. returns 
 * the malloced void *.
 * 
 * @param size 
 * @return void* 
 */
void	*pmalloc(size_t	size)
{
	void	*new;

	new = ft_calloc(size, 1);
	if (!new)
		exit_error_message("");
	return (new);
}

int	is_split_c(char c)
{
	if (c == '\"' || c == '\'' || c == ' ' || c == '\0')
		return (1);
	return (0);
}

void	exit_error(char *msg, int exitcode)
{
	ft_putstr_fd(msg, 2);
	exit(exitcode);
}

/**
 * @brief checks if a env variable is in str. If so return true else false
 * 
 * @param str 
 * @return char* 
 */
t_bool	env_in_str(char *str, char **envp)
{
	if (!ft_strchr(str, '$'))
		return (false);
	if (find_env_var(str, envp))
		return (true);
	return (false);
}
