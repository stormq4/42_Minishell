/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   append_word.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 16:13:58 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/30 10:19:21 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief checks if the first word needs to be appended to the cmd of 
 * the t_exec member. Otherwise it is appended to the cmd member.
 * 
 * @param command t_command 
 * @param token t_token
 * @param token_lst t_list
 */
static void	check_first_word(t_command *command, t_token *token, \
t_list **token_lst)
{
	char	*str_space;

	if (command->exec->cmd != NULL)
	{
		str_space = ft_strjoin(command->exec->cmd, " ");
		ft_check_malloc(str_space);
		free(command->exec->cmd);
		command->exec->cmd = ft_strjoin(str_space, token->token_data);
		ft_check_malloc(command->exec->cmd);
		free(str_space);
	}
	else
		command->exec->cmd = ft_strdup(token->token_data);
	*token_lst = (*token_lst)->next;
}

/**
 * @brief appends a word to the cmd member in the t_exec struct
 * 
 * @param token_lst token_lst of tokens
 * @param command current command
 * @param token token to be added
 */
void	append_word(t_list **token_lst, t_command *command, t_token *token)
{
	token = (t_token *)(*token_lst)->ct;
	while (token->type == e_word && *token_lst)
	{
		check_first_word(command, token, token_lst);
		if (*token_lst)
			token = (t_token *)(*token_lst)->ct;
	}
}
