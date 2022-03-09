/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 08:45:09 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 11:40:30 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// header files in inc folder
# include "lexer.h"

/**
 * @brief minshell struct
 * 
 * @param lexer struct for lexer part
 */
typedef struct s_minishell {
	t_lexer	lexer;
}				t_minishell;

// free_shell.c
void	free_shell(t_minishell *shell);

#endif
