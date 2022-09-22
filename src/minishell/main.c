/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:19:51 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/22 11:14:29 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	t_minishell	shell;
	char		**envp;
	t_bool		running;

	envp = initialize_shell(&shell);
	running = true;
	while (running)
		running = run_shell(&shell, &envp);
	free_env(envp);
	return (EXIT_SUCCESS);
}
