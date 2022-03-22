/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 13:26:39 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/22 15:20:55 by sde-quai      ########   odam.nl         */
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
static void	categorize_cmd_line(t_token **tokens, size_t *i, char str_i, \
const char *cmd_line)
{
	if (str_i == space)
		return ;
	else if (str_i == s_quote)
		find_next_quote(tokens, i, s_quote, cmd_line);
	else if (str_i == d_quote)
		find_next_quote(tokens, i, d_quote, cmd_line);
	else if (str_i == c_pipe)
		categorize_pipe(tokens);
	else if (str_i == red_in)
		categorize_redirects(tokens, i, red_in, cmd_line);
	else if (str_i == red_out)
		categorize_redirects(tokens, i, red_out, cmd_line);
	else if (ft_isascii(str_i))
		find_next_word(tokens, i, cmd_line); //quotes and redirects as well
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
t_token	*lexer(const char *cmd_line)
{
	t_token	*tokens;
	size_t	i;
	size_t	len;

	tokens = NULL;
	len = ft_strlen(cmd_line);
	i = 0;
	while (i < len)
	{
		categorize_cmd_line(&tokens, &i, cmd_line[i], cmd_line);
		i++;
	}
	return (tokens);
}