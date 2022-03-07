/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 13:26:39 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/07 17:03:24 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

t_token	*realloc_tokens(t_token *tokens, size_t count, size_t size)
{
	size_t	i;
	t_token *new_tokens;

	if (count == 1)
	{
		tokens = malloc(count * size);
		ft_check_malloc(tokens);
		return (tokens);
	}
	new_tokens = malloc(count * size);
	ft_check_malloc(tokens);
	i = 0;
	while (i < count - 1)
	{
		new_tokens[i] = tokens[i];
		i++;
	}
	free(tokens);
	return (new_tokens);
}

void	find_next_quote(t_lexer *lexer, size_t *i, t_character quote)
{
	size_t j;

	lexer->token_nr++;
	realloc_tokens(lexer->tokens, lexer->token_nr, sizeof(t_lexer));
	j = ft_strlen_c(&lexer->cmd_line[*i + j], quote);
	
}

void categorize_lexer(t_lexer *lexer, size_t *i, char str_i)
{
	if (str_i == s_quote)
		find_next_quote(lexer, i, s_quote);
	else if (str_i = d_quote)
		find_next_quote(lexer, i, d_quote);
	// else if (str_i == '|')
		
	// else if (str_i == '<')
		
	// else if (str_i == '>')
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
