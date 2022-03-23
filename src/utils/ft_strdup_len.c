/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup_len.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 16:09:50 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/23 11:13:03 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief strdup's part of the string up to len
 * 
 * @param str input string
 * @param len characters
 * @return char* 
 */
char	*ft_strdup_len(const char *str, size_t len)
{
	size_t	i;
	char	*new_str;

	if (ft_strlen(str) < len)
		len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	ft_check_malloc(new_str);
	i = 0;
	while (i < len && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
