/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_pipes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 09:55:03 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/09 10:26:05 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	categorize_pipe(t_lexer *lexer, size_t *i)
{
	t_token	*token;

	token = lexer_lstnew();
	token->token_id = lexer->token_nr;
	lexer->token_nr++;
	token->token_data = ft_strdup("|");
	ft_check_malloc(token->token_data);
	token->type = e_pipe;
	lexer_lstadd_back(&lexer->tokens, token);
	(*i)++;
}
