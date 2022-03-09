/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:19:51 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 17:16:47 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// add parser expander
int	main(int argc, char **argv, char **envp)
{
	t_minishell	shell;

	while (1)
	{
		initialize_structs(&shell);
		shell.lexer = lexer(&*shell.lexer);
		free_shell(&shell);
	}
	return (0);
}
