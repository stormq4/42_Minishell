/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 13:26:39 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/07 17:51:38 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "utils.h"

void	find_next_quote(t_lexer *lexer, size_t *i, t_character quote)
{
	size_t	j;
	t_token	*token;

	lexer->token_nr++;
	j = ft_strlen_c(&lexer->cmd_line[*i + j], quote);
	token->token_id = lexer->token_nr;
	token->token_data = ft_strdup_c(&lexer->cmd_line[*i + j], quote);
	token->type = e_word;
	token = lexer_lstnew(token);
	lexer_lstadd_back(&lexer->tokens, token);
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
