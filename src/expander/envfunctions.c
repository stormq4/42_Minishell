/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envfunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:50:25 by gpirro            #+#    #+#             */
/*   Updated: 2022/09/17 10:07:21 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

/**
 * @brief checks if a env variable is in str. If so replace it with its
 * value and return the new str.
 * 
 * @param str 
 * @return char* 
 */
char	*replace_env_var(char *str, char **envp)
{
	char	*bef;
	char	*aft;
	char	*envvar;
	char	*replacer;
	char	*tmp;

	if (!ft_strchr(str, '$'))
		return (NULL);
	bef = bef_env_var(str);
	if (find_env_var(str, envp))
		envvar = find_env_var(str, envp);
	else
	{
		free(bef);
		return (NULL);
	}
	aft = aft_env_var(str);
	replacer = ft_strjoin(bef, envvar);
	tmp = replacer;
	replacer = ft_strjoin(tmp, aft);
	free(tmp);
	free(bef);
	free(aft);
	return (replacer);
}

t_bool	check_special_expand(char a)
{
	if (a == 35)
		return (true);
	else if (a >= 42 && a <= 47)
		return (true);
	else if (a == 58)
		return (true);
	else if (a == 61)
		return (true);
	else if (a >= 63 && a <= 64)
		return (true);
	else if (a == 91)
		return (true);
	else if (a >= 93 && a <= 95)
		return (true);
	else if (a == 123)
		return (true);
	else if (a >= 125 && a <= 126)
		return (true);
	return (false);
}

/**
 * @brief free's old
 * 
 * @param split 
 * @return int 
 */
int	replace_env_var_in_lst(t_list **split, char **envp)
{
	char		*tmp;
	t_expand	*expand;

	while (*split)
	{
		expand = (t_expand *)(*split)->ct;
		if (expand->expand == 1)
		{
			if (env_in_str(expand->split, envp) && \
			!has_special_expand_char(expand->split))
			{
				tmp = expand->split;
				expand->split = replace_env_var(expand->split, envp);
				free(tmp);
			}
			else if (env_in_special(expand->split, envp))
			{
				tmp = expand->split;
				expand->split = replace_special_var(expand->split, envp);
				free(tmp);
			}
		}
		split = &(*split)->next;
	}
	return (1);
}

/**
 * @brief returns the str after the env variable.
 * 
 * @param str 
 * @return char* 
 */
char	*aft_env_var(char *str)
{
	int		i;
	int		j;
	char	*end;

	i = ft_strchr(str, '$') - str;
	while (str[i] && str[i] != '\'' && str[i] != ' ')
		i++;
	end = pmalloc(sizeof(char) * (ft_strlen(str) - i + 1));
	j = -1;
	i--;
	while (str[i++])
		end[++j] = str[i];
	end[j] = 0;
	return (end);
}

/**
 * @brief returns str before the env var in str
 * 
 * @param str 
 * @return char* 
 */
char	*bef_env_var(char *str)
{
	char	*bef;

	bef = ft_strdup_c(str, '$');
	if (!bef)
		exit_error_message("");
	return (bef);
}
