/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 14:35:11 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/22 10:30:47 by sde-quai      ########   odam.nl         */
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
	lexer_lstclear(&shell->tokens);
}
