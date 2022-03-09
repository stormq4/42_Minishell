/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 13:26:39 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 10:25:52 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	categorize_lexer(t_lexer *lexer, size_t *i, char str_i)
{
	if (str_i == space)
		return ;
	else if (str_i == s_quote)
		find_next_quote(lexer, i, s_quote);
	else if (str_i == d_quote)
		find_next_quote(lexer, i, d_quote);
	else if (ft_isascii(str_i))
		find_next_space(lexer, i);
	else if (str_i == c_pipe)
		categorize_pipe(lexer, i);
	else if (str_i == red_in)
		categorize_redirects(lexer, i, red_in);
	else if (str_i == red_out)
		categorize_redirects(lexer, i, red_out);
}

void	lexer(t_lexer *lexer)
{
	size_t	i;

	lexer->cmd_line = readline("minishell> ");
	lexer->token_nr = 0;
	i = 0;
	while (lexer->cmd_line[i])
	{
		categorize_lexer(lexer, &i, lexer->cmd_line[i]);
		i++;
	}
}
