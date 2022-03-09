/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 17:19:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 11:28:56 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief mallocs a new t_token struct. Null points next attribute.
 * 
 * @return t_token* 
 */
t_token	*lexer_lstnew(void)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	ft_check_malloc(new_token);
	new_token->next = NULL;
	return (new_token);
}

/**
 * @brief moves to the last attribute of the t_token link list
 * 
 * @param lst begin of the list
 * @return t_token* last t_token of the list
 */
t_token	*lexer_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/**
 * @brief adds new list to the end of the list of the list
 * 
 * @param lst points to the link list
 * @param new is the list that needs to be added at the back
 */
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

/**
 * @brief clears and frees the list
 * 
 * @param lst points to the first list of the link list
 */
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
