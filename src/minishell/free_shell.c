/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 14:35:11 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/08 15:44:47 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "minishell.h"

void	free_shell(t_minishell *shell)
{
	lexer_lstclear(&shell->lexer->tokens);
}
