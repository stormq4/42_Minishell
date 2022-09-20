/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 08:45:09 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/15 14:31:23 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// header files in inc folder
# include "executor.h"
# include "expander.h"

/**
 * @brief minshell struct
 * 
 * @param 
 */
typedef struct s_minishell {
	char		*cmd_line;
	t_list		*tokens;
	t_list		*b_tokens;
	t_list		*parser;
	t_list		*b_parser;
}				t_minishell;

// free_shell.c
void	free_shell(t_minishell *shell);
void	free_env(char **env);

t_bool	run_shell(t_minishell *shell, char ***envp);
char	**initialize_shell(t_minishell *shell);

#endif
