/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 14:35:11 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/09 16:23:09 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "minishell.h"

/**
 * @brief frees the shell attributes such as lexer .... add more!!
 * 
 * @param shell struct
 */
void	free_shell(t_minishell *shell)
{
	t_token	*token_lst;

	token_lst = shell->lexer->tokens;
	lexer_lstclear(&token_lst);
	free(shell->lexer->cmd_line);
	free(shell->lexer);
}
