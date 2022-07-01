/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errcode.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 11:50:25 by gpirro        #+#    #+#                 */
/*   Updated: 2022/06/28 13:43:08 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

/**
 * @brief returns the str after the env variable.
 * 
 * @param str 
 * @return char* 
 */
char	*aft_g_error(char *str)
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
char	*bef_g_error(char *str)
{
	char	*bef;

	bef = ft_strdup_c(str, '$');
	if (!bef)
		exit_error_message("");
	return (bef);
}

/**
 * @brief checks if a env variable is in str. If so replace it with its
 * value and return the new str.
 * 
 * @param str 
 * @return char* 
 */
char	*replace_g_error(char *str)
{
	char	*bef;
	char	*aft;
	char	*error;
	char	*replaced;
	char	*tmp;

	if (!ft_strchr(str, '$'))
		return (NULL);
	bef = bef_g_error(str);
	error = ft_itoa(g_error);
	tmp = ft_strjoin(bef, error);
	aft = aft_g_error(str);
	replaced = ft_strjoin(tmp, aft);
	free(tmp);
	free(error);
	free(bef);
	free(aft);
	return (replaced);
}

/**
 * @brief checks if a env variable is in str. If so return true else false
 * 
 * @param str 
 * @return char* 
 */
t_bool	exit_code_in_str(char *str)
{
	char	*line;

	line = ft_strchr(str, '$');
	if (!line)
		return (false);
	if (ft_strncmp(line, "$?", 2))
		return (false);
	return (true);
}

/**
 * @brief free's old
 * 
 * @param split 
 * @return int 
 */
int	replace_g_error_in_lst(t_list **split)
{
	char		*tmp;
	t_expand	*expand;

	while (*split)
	{
		expand = (t_expand *)(*split)->ct;
		if (expand->expand == 1)
		{
			if (exit_code_in_str(expand->split))
			{
				tmp = expand->split;
				expand->split = replace_g_error(expand->split);
				free(tmp);
			}
		}
		split = &(*split)->next;
	}
	return (1);
}
