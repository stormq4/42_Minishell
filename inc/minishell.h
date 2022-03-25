/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 08:45:09 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/25 10:30:24 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// header files in inc folder
# include "lexer.h"
# include "parser.h"

/**
 * @brief minshell struct
 * 
 * @param 
 */
typedef struct s_minishell {
	const char	*cmd_line;
	t_token		*tokens;
}				t_minishell;

// free_shell.c
void	free_shell(t_minishell *shell);

// initialize_sturcts.c
void	initialize_structs(t_minishell *shell);

#endif
