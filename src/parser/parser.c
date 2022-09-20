/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 09:50:25 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/15 14:26:36 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief appends a redirect or word from the token list
 * 
 */
t_bool	add_token_2_command(t_token *token, t_command *command, \
t_list **token_lst)
{
	if (token->type == e_word)
		append_word(token_lst, command, token);
	else
		if (!append_redirect(token_lst, command, token))
			return (false);
	return (true);
}

/**
 * @brief creates a new command structs and fills it with input ouput
 * and executable structs
 * 
 * @return t_command* 
 */
static t_command	*new_command(void)
{
	t_command	*command;
	t_red		*in;
	t_red		*out;

	command = malloc(sizeof(t_command));
	ft_check_malloc(command);
	command->exec = malloc(sizeof(t_exec));
	ft_check_malloc(command->exec);
	command->exec->cmd = NULL;
	in = malloc(sizeof(t_red));
	ft_check_malloc(in);
	in->file = NULL;
	command->in = ft_lstnew(in);
	out = malloc(sizeof(t_red));
	ft_check_malloc(out);
	out->file = NULL;
	command->out = ft_lstnew(out);
	return (command);
}

/**
 * @brief The parser creates the structure of the commands between the pipes.
 * The redirects are combined with words and the rest of the words combined 
 * an excecutable. If a pipe is found a new command is added to the list.
 * 
 * @param token_lst 
 * @return t_list* of commands i returned
 */
t_bool	parser(t_list **token_lst, t_list **b_lst)
{
	t_list		*cmd_lst;
	t_command	*command;
	t_token		*token;

	command = new_command();
	cmd_lst = ft_lstnew(command);
	*b_lst = cmd_lst;
	while (*token_lst)
	{
		token = (t_token *)(*token_lst)->ct;
		if (token->type != e_pipe)
		{
			if (!add_token_2_command(token, command, token_lst))
				return (false);
		}
		else
		{
			cmd_lst->next = ft_lstnew(new_command());
			cmd_lst = cmd_lst->next;
			command = (t_command *)cmd_lst->ct;
			*token_lst = (*token_lst)->next;
		}
	}
	return (true);
}
