/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:35:12 by sde-quai          #+#    #+#             */
/*   Updated: 2022/09/16 18:57:19 by gianlucapir      ###   ########.fr       */
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
		new = ft_strjoin(tmp, (char *)expand->split);
		if (!new)
			exit_error_message("");
		free(tmp);
		tmp_split = tmp_split->next;
	}
	return (new);
}

char	*order_lst_join(t_list	**order)
{
	char	*new;
	char	*tmp;
	t_list	*current;

	new = ft_strdup("");
	if (!new)
		exit_error_message("");
	current = (*order);
	while (current != NULL)
	{
		tmp = new;
		new = ft_strjoin(tmp, (char *)current->ct);
		if (!new)
			exit_error_message("");
		free(tmp);
		current = current->next;
	}
	return (new);
}

void	free_order_lst(t_list *order)
{
	t_list		*tmp;

	while (order != NULL)
	{
		free(order->ct);
		tmp = order->next;
		free(order);
		order = tmp;
	}
	free(order);
}
