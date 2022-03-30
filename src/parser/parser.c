/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 09:50:25 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/30 09:39:58 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief 
 * dikke bullshit functie. Dit is alleen om de tester te kunnen compilen.
 * 
 * je moet alle attributen malloccen en vullen zodat je geen undifined 
 * behavior en seg(x)-faults krijgt.
 */
t_list	*parser(t_list **token_lst)
{
	t_list		*commands;
	t_command	*cmd;
	t_red		*in;
	t_red		*out;
	t_red		*heredoc;
	
	cmd = malloc(sizeof(t_command));
	cmd->exec = malloc(sizeof(t_exec));
	cmd->exec->args = ft_split("hallo ik ben dom", ' ');
	cmd->exec->cmd = ft_strdup("hallo ik ben dom");
	commands = ft_lstnew(cmd);
	in = malloc(sizeof(t_red));
	in->fd = -1;
	in->type = 10000;
	in->file = ft_strdup("hallo");
	out = malloc(sizeof(t_red));
	out->file = ft_strdup("hallo");
	out->fd = -1;
	out->type = 10000;
	heredoc = malloc(sizeof(t_red));
	heredoc->file = ft_strdup("hallo");
	out->fd = -1;
	out->type = 10000;
	cmd->heredoc = ft_lstnew(heredoc);
	cmd->in = ft_lstnew(in);
	cmd->out = ft_lstnew(out);
	(void)token_lst;
	return (commands);
}
