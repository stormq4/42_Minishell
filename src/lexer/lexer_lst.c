/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 17:19:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/07 17:49:27 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*lexer_lstnew(t_token *add_token)
{
	t_token	*new_token;

	if (!add_token)
		return (NULL);
	new_token = malloc(sizeof(t_token));
	ft_check_malloc(new_token);
	new_token = add_token;
	new_token->next = NULL;
	return (new_token);
}

t_token	*lexer_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lexer_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*tmp;

	tmp = *lst;
	if (!tmp)
	{
		tmp = new;
		return ;
	}
	tmp = ft_lstlast(tmp);
	tmp->next = new;
	new->next = NULL;
}
