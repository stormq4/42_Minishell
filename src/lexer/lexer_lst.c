/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_lst.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 17:19:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 17:16:35 by sde-quai      ########   odam.nl         */
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
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
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

	if (*lst)
	{
		tmp = lexer_lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}

/**
 * @brief clears and frees the link list of tokens
 * 
 * @param lst points to the first list of the link list
 */
void	lexer_lstclear(t_token **lst)
{
	t_token	*tmp;
	t_token	*deref_lst;

	if (!lst)
		return ;
	deref_lst = *lst;
	while (deref_lst)
	{
		tmp = deref_lst;
		deref_lst = tmp->next;
		printf("tmp->token_data --> %s\n", tmp->token_data); // weg
		free(tmp->token_data);
		free(tmp);
	}
}
