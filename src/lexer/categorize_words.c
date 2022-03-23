/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_words.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 09:43:27 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/23 11:07:28 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief finds the minimum length in one of the special
 * charachters given below
 * 
 * @param cmd_line prompted command line
 * @param i incrementer of the string
 * @return size_t smallest value of earliest special charachter
 * int string
 */
static size_t find_min_char(const char *cmd_line, size_t *i)
{
	size_t	j_n[6];
	size_t	j;

	j_n[0] = ft_strlen_c(&cmd_line[*i], space);
	j_n[1] = ft_strlen_c(&cmd_line[*i], s_quote);
	j_n[2] = ft_strlen_c(&cmd_line[*i], d_quote);
	j_n[3] = ft_strlen_c(&cmd_line[*i], red_in);
	j_n[4] = ft_strlen_c(&cmd_line[*i], red_out);
	j_n[5] = ft_strlen_c(&cmd_line[*i], c_pipe);
	j = find_min_size_t(j_n, 6);
	return (j);
}

/**
 * @brief If a ascii character (except space ) is found the next space or
 * end of line a token is created and put into the token_dat
 * 
 * @param tokens list 
 * @param i this pointer index is increased since it cuts a part of the string
 * @param cmd_line is the prompted commandline
 */
void	find_next_word(t_token **tokens, size_t *i, const char *cmd_line)
{
	size_t	j;
	t_token	*new;

	new = lexer_lstnew();
	j = find_min_char(cmd_line, i);
	new->token_data = ft_strdup_len(&cmd_line[*i], j);	
	ft_check_malloc(new->token_data);
	new->type = e_word;
	lexer_lstadd_back(tokens, new);
	(*i) += j - 1;
}

/**
 * @brief This function finds the next quote pair and generates a token with
 * it. The full string is placed in the token_data.
 * 
 * @param tokens list
 * @param i this pointer index is increased since it cuts a part of the string
 * @param quote single quote or double quote
 * @param cmd_line is the prompted commandline
 */
void	find_next_quote(t_token **tokens, size_t *i, t_character quote, \
const char *cmd_line)
{
	size_t	j;
	t_token	*new;

	new = lexer_lstnew();
	j = ft_strlen_c(&cmd_line[*i + 1], quote) + 1;
	new->token_data = ft_strdup_len(&cmd_line[*i], j + 1);
	new->type = e_word;
	lexer_lstadd_back(tokens, new);
	(*i) += j;
}
