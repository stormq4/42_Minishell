/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_redirects.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 10:31:57 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/08 15:34:31 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"

static void	single_redirect(t_lexer *lexer, size_t *i, t_character red, \
t_token *token)
{
	token->token_data = malloc(sizeof(char) * 1 + 1);
	ft_check_malloc(token->token_data);
	token->token_data[0] = red;
	token->token_data[1] = 0;
	if (red == red_in)
		token->type = e_red_heredoc;
	else
		token->type = e_red_out_append;
	i++;
}

static void	double_redirect(t_lexer *lexer, size_t *i, t_character red, \
t_token *token)
{
	token->token_data = malloc(sizeof(char) * 2 + 1);
	ft_check_malloc(token->token_data);
	token->token_data[0] = red;
	token->token_data[1] = red;
	token->token_data[2] = 0;
	if (red == red_in)
		token->type = e_red_in;
	else
		token->type = e_red_out_trunc;
	i += 2;
}

void	categorize_redirects(t_lexer *lexer, size_t *i, t_character red)
{
	t_token	*token;

	lexer->token_nr++;
	token->token_id = lexer->token_nr;
	if (lexer->cmd_line[*i + 1] == red)
		double_redirect(lexer, i, red, token);
	else
		single_redirect(lexer, i, red, token);
	token = lexer_lstnew(token);
	lexer_lstadd_back(&lexer->tokens, token);
}
