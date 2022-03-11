/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_redirects.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 10:31:57 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/11 12:29:00 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief adds a single redirect token to the token link list
 * 
 * @param i index for loaction of cmd_line
 * @param red redirect < or >
 * @param token lst
 */
static void	single_redirect(t_character red, \
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
}

/**
 * @brief adds a double redirect token to the token link list
 * 
 * @param i index for loaction of cmd_line
 * @param red redirect < or >
 * @param token lst
 */
static void	double_redirect(size_t *i, t_character red, \
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
	(*i)++;
}

/**
 * @brief adds a single or double redirect token to the token link list
 * 
 * @param lexer struct
 * @param i index for loaction of cmd_line
 * @param red redirect < or >
 */
void	categorize_redirects(t_lexer *lexer, size_t *i, t_character red)
{
	t_token	*token;

	token = lexer_lstnew();
	token->token_id = lexer->token_nr;
	lexer->token_nr++;
	if ((t_character)lexer->cmd_line[*i + 1] == red)
		double_redirect(i, red, token);
	else
		single_redirect(red, token);
	lexer_lstadd_back(&lexer->tokens, token);
}
