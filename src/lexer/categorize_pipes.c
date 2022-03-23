/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_pipes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 09:55:03 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/23 10:48:07 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief if a pipe (|) character is recognized then a pipe new token 
 * is created
 * 
 * @param tokens is the token list
 */
void	categorize_pipe(t_token **tokens)
{
	t_token	*new;

	new = lexer_lstnew();
	new->token_data = ft_strdup("|");
	ft_check_malloc(new->token_data);
	new->type = e_pipe;
	lexer_lstadd_back(tokens, new);
}
