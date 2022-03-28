/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_delete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:48:01 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/28 15:19:41 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	red_delete(void *ct)
{
	t_red	*red;

	red = (t_red *)ct;
	free((void *)red->file);
	free(red);
}

void	parser_delete(void *ct)
{
	t_command *command;

	command = (t_command *)ct;
	if (command->in)
		ft_lstclear(&command->in, red_delete);
	if (command->out)
		ft_lstclear(&command->out, red_delete);
	if (command->heredoc)
		ft_lstclear(&command->heredoc, red_delete);
	if (command->exec)
	{
		free((void *)command->exec->cmd);
		ft_split_free(command->exec->args);
	}
	free(command);
}