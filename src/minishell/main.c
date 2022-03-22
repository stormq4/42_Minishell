/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:19:51 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/22 11:06:28 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell	shell;
	const char	*cmd_line;

	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		// initialize_structs(&shell);
		cmd_line = readline("minishell> ");
		shell.tokens = lexer(cmd_line);
		free_shell(&shell);
	}
	return (0);
}
