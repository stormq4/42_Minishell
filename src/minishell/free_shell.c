/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 14:35:11 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/06/29 17:29:06 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief frees the shell attributes such as lexer .... add more!!
 * 
 * @param shell struct
 */
void	free_shell(t_minishell *shell)
{
	if (shell->cmd_line)
		free((void *)shell->cmd_line);
	if (shell->b_tokens)
		ft_lstclear(&shell->b_tokens, token_delete);
	if (shell->b_parser)
		ft_lstclear(&shell->b_parser, parser_delete);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}
