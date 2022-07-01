/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_split.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 13:14:38 by gpirro        #+#    #+#                 */
/*   Updated: 2022/06/28 13:42:51 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	free_split(t_list **lstsplit)
{
	t_list		*split;
	t_expand	*item;
	t_list		*tmp;

	split = *lstsplit;
	while (split)
	{
		item = (t_expand *)split->ct;
		free(item->split);
		free(item);
		tmp = split;
		split = split->next;
		free(tmp);
	}
	free(split);
}
