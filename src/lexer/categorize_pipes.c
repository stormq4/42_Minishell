/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_pipes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 09:55:03 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/22 11:18:10 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief if a pipe (|) character is recognized then a pipe new token 
 * is created
 * 
 * @param lexer 
 * @param i this pointer index is incremented since it cuts a part of the 
 * string
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
