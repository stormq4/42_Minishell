/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_structs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 16:02:58 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 17:13:25 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief initialize structs within the shell struct
 * 
 * @param shell struct
 */
void	initialize_structs(t_minishell *shell)
{
	shell->lexer = malloc(sizeof(t_lexer));
	ft_check_malloc(shell->lexer);
}
