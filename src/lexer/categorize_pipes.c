/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_pipes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 09:55:03 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/05/19 10:36:26 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief if a pipe (|) character is recognized then a pipe new token 
 * is created
 * 
 * @param tokens is the token list
 */
void	categorize_pipe(t_list **tokens)
{
	t_list	*new;
	t_token	*token_ct;

	token_ct = malloc(sizeof(t_token));
	ft_check_malloc(token_ct);
	token_ct->token_data = ft_strdup("|");
	ft_check_malloc(token_ct->token_data);
	token_ct->type = e_pipe;
	new = ft_lstnew(token_ct);
	ft_check_malloc(new);
	ft_lstadd_back(tokens, new);
}
