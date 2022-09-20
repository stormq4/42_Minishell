/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envfunction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:45:51 by sde-quai          #+#    #+#             */
/*   Updated: 2022/09/17 10:28:03 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	has_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

char	*get_env_val(char *var, char **envp)
{
	int		i;
	int		varlen;
	int		envvarlen;

	i = -1;
	while (envp[++i])
	{
		varlen = ft_strlen(var);
		envvarlen = ft_strlen(envp[i]) - ft_strlen(ft_strchr(envp[i], '='));
		if (ft_strncmp(var, envp[i], ft_strlen(var)) == 0 && \
		varlen == envvarlen)
			return (ft_strchr(envp[i], '=') + 1);
	}
	if (has_digit(var))
		return ("");
	return (NULL);
}

/**
 * @brief finds the env var in the str and returns its value,
 * if env var does not exist return (null)
 * 
 * @param str 
 * @return char* 
 */
char	*find_env_var(char *str, char **envp)
{
	int		i;
	int		tmp;
	char	*var;
	char	*tmp2;

	i = ft_strchr(str, '$') - str;
	tmp = i;
	while (str[i] && str[i] != '\'' && str[i] != ' ')
		i++;
	i -= tmp;
	var = ft_strdup_len(ft_strchr(str, '$') + 1, i - 1);
	if (!var)
		exit_error_message("");
	tmp2 = var;
	var = get_env_val(tmp2, envp);
	free(tmp2);
	return (var);
}
