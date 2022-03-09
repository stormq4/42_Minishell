/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 17:19:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 10:28:11 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token	*lexer_lstnew(void)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	ft_check_malloc(new_token);
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
	tmp = lexer_lstlast(tmp);
	tmp->next = new;
	new->next = NULL;
}

void	lexer_lstclear(t_token **lst)
{
	t_token	*tmp;
	t_token	*der_lst;

	if (!lst)
		return ;
	der_lst = *lst;
	while (der_lst)
	{
		tmp = der_lst;
		der_lst = der_lst->next;
		free(tmp->token_data);
		free(tmp);
	}
}
