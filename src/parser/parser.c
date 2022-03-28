/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 09:50:25 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/28 14:05:20 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*parser(t_list **token_lst)
{
	t_list		*commands;
	t_command	*cmd;

	cmd = ft_calloc(1, sizeof(cmd));
	ft_check_malloc(ft_calloc);
	commands = ft_lstnew(cmd);
	(void)token_lst;
	return (commands);
}
