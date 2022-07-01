/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/28 10:35:12 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/28 13:42:44 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

/**
 * @brief joins every item of the list together in a str
 * and returns this.
 * 
 * @param split 
 * @return char* 
 */
char	*lst_join(t_list **split)
{
	char		*new;
	char		*tmp;
	t_expand	*expand;
	t_list		*tmp_split;

	new = ft_strdup("");
	if (!new)
		exit_error_message("");
	tmp_split = (*split);
	while (tmp_split)
	{
		tmp = new;
		expand = (t_expand *)tmp_split->ct;
		new = ft_strjoin(tmp, expand->split);
		if (!new)
			exit_error_message("");
		free(tmp);
		tmp_split = tmp_split->next;
	}
	return (new);
}
