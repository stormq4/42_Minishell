/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_words.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 09:43:27 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/09 10:26:13 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	find_next_space(t_lexer *lexer, size_t *i)
{
	size_t	j;
	t_token	*token;

	token = lexer_lstnew();
	token->token_id = lexer->token_nr;
	lexer->token_nr++;
	j = ft_strlen_c(&lexer->cmd_line[*i], space);
	token->token_data = ft_strdup_c(&lexer->cmd_line[*i], space);
	ft_check_malloc(token->token_data);
	token->type = e_word;
	lexer_lstadd_back(&lexer->tokens, token);
	(*i) += j;
}

void	find_next_quote(t_lexer *lexer, size_t *i, t_character quote)
{
	size_t	j;
	t_token	*token;

	token = lexer_lstnew();
	token->token_id = lexer->token_nr;
	lexer->token_nr++;
	j = ft_strlen_c(&lexer->cmd_line[*i + 1], quote) + 1;
	token->token_data = ft_strdup_len(&lexer->cmd_line[*i], j);
	token->type = e_word;
	lexer_lstadd_back(&lexer->tokens, token);
	(*i) += j;
}
