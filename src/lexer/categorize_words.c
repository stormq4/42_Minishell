/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   categorize_words.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 09:43:27 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/06/28 17:19:15 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief appends a string to token_data
 * 
 * @param token
 * @param tmp_str
 */
static void	join_token_data(t_token *token, char *tmp_str)
{
	char	*free_str;

	if (token->token_data)
	{
		free_str = token->token_data;
		token->token_data = ft_strjoin(free_str, tmp_str);
		ft_check_malloc(token->token_data);
		free(free_str);
		free(tmp_str);
	}
	else
		token->token_data = tmp_str;
}

/**
 * @brief finds the end of the word with quotes or not
 * 
 * @param i 
 * @param cmd_line 
 * @param token 
 */
static void	find_end_word(size_t *i, const char *cmd_line, t_token *token)
{
	size_t	j;
	char	*tmp_str;

	if (cmd_line[*i] != s_quote && cmd_line[*i] != d_quote)
	{
		j = find_min_char(cmd_line, i);
		tmp_str = ft_strdup_len(&cmd_line[*i], j);
		ft_check_malloc(tmp_str);
		(*i) += j - 1;
	}
	else
	{
		j = ft_strlen_c(&cmd_line[*i + 1], cmd_line[*i]) + 1;
		tmp_str = ft_strdup_len(&cmd_line[*i], j + 1);
		(*i) += j;
	}
	join_token_data(token, tmp_str);
}

/**
 * @brief finds the full next word in the commandline
 * 
 * @param token_lst 
 * @param i 
 * @param cmd_line 
 */
void	find_next_word(t_list **token_lst, size_t *i, const char *cmd_line)
{
	t_token	*token;
	t_list	*new;

	token = malloc(sizeof(t_token));
	ft_check_malloc(token);
	token->type = e_word;
	token->token_data = NULL;
	while (check_char_for_word(cmd_line[*i]))
	{
		find_end_word(i, cmd_line, token);
		(*i)++;
	}
	new = ft_lstnew(token);
	ft_check_malloc(new);
	ft_lstadd_back(token_lst, new);
}
