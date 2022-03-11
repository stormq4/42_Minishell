/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 13:26:39 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/11 19:03:55 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

/**
 * @brief every character in the command line is checked. The index is 
 * incremented in the given functions. For quotes and ascii (except spaces)
 * words are generated. For redirects (< and >) redirects tokens are 
 * generated and for the pipes (|) as well.
 * 
 * @param lexer struct
 * @param i is incremented in the scope int thelexer() function
 * @param str_i is the charcter being in the cmd_line
 */
static void	categorize_lexer(t_lexer *lexer, size_t *i, char str_i)
{
	if (str_i == space)
		return ;
	else if (str_i == s_quote)
		find_next_quote(lexer, i, s_quote);
	else if (str_i == d_quote)
		find_next_quote(lexer, i, d_quote);
	else if (str_i == c_pipe)
		categorize_pipe(lexer);
	else if (str_i == red_in)
		categorize_redirects(lexer, i, red_in);
	else if (str_i == red_out)
		categorize_redirects(lexer, i, red_out);
	else if (ft_isascii(str_i))
		find_next_space(lexer, i);
}

/**
 * @brief The lexer categorizes (and tokenizes) the string from the 
 * command line in words, pipes and redirects. The readline prompts 
 * a string from the commandline. Every charachter is parsed and 
 * passed to the categorize lexer function.
 * 
 * @param shell struct
 * @return *t_lexer filled lexer struct
 */
t_lexer	*lexer(t_lexer *lexer)
{
	size_t	i;

	lexer->tokens = NULL;
	lexer->token_nr = 0;
	i = 0;
	while (lexer->cmd_line[i])
	{
		categorize_lexer(lexer, &i, lexer->cmd_line[i]);
		i++;
	}
	return (lexer);
}
