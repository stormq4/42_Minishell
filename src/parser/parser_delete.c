/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_delete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 13:48:01 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/29 17:37:31 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief 
 * 
 * @param ct 
 */
static void	red_delete(void *ct)
{
	t_red	*red;

	red = (t_red *)ct;
	if (!red)
		return ;
	if (red->file)
		free((void *)red->file);
	free(red);
}

/**
 * @brief 
 * 
 * @param ct 
 */
void	parser_delete(void *ct)
{
	t_command	*command;

	if (!ct)
		return ;
	command = (t_command *)ct;
	if (command->in)
		ft_lstclear(&command->in, red_delete);
	if (command->out)
		ft_lstclear(&command->out, red_delete);
	if (command->exec)
	{
		if (command->exec->cmd)
			free(command->exec->cmd);
		free(command->exec);
	}
	free(command);
}
