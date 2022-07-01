/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_redirects.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 10:31:57 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/05/20 10:57:00 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief adds a single redirect token to the token link list
 * 
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
		token->type = e_s_in;
	else
		token->type = e_s_out;
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
		token->type = e_d_in;
	else
		token->type = e_d_out;
	(*i)++;
}

/**
 * @brief adds a single or double redirect token to the token link list
 * 
 * @param tokens list
 * @param i index for loaction of cmd_line in ASCI vlaue
 * @param red redirect < or >
 * @param cmd_line is the prompted commandline
 */
void	categorize_redirects(t_list **tokens, size_t *i, t_character red, \
const char *cmd_line)
{
	t_token	*token_ct;
	t_list	*new;

	token_ct = malloc(sizeof(t_token));
	ft_check_malloc(token_ct);
	if ((t_character)cmd_line[*i + 1] == red)
		double_redirect(i, red, token_ct);
	else
		single_redirect(red, token_ct);
	(*i)++;
	new = ft_lstnew(token_ct);
	ft_lstadd_back(tokens, new);
}
