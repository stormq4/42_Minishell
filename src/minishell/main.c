/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:19:51 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/15 14:40:56 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell	shell;

	(void)argc;
	(void)argv;
	(void)envp;
	while (1)
	{
		initialize_structs(&shell);
		shell.lexer->cmd_line = readline("minishell> ");
		shell.lexer = lexer(&*shell.lexer);
		free_shell(&shell);
	}
	return (0);
}
