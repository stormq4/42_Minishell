/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_shell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:32:25 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/20 10:32:36 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_error = 0;

char	**initialize_shell(t_minishell *shell)
{
	extern char	**environ;
	char		**envp;

	shell->b_parser = NULL;
	shell->b_tokens = NULL;
	shell->parser = NULL;
	shell->tokens = NULL;
	signal(SIGINT, signal_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	envp = malloc_env(environ);
	adjust_shlvl(envp, true);
	adjust_location(envp);
	unset_var("OLDPWD", &envp);
	return (envp);
}

//, shell) in executor line 51;
t_bool	run_shell(t_minishell *shell, char ***envp)
{
	shell->cmd_line = readline("minishell> ");
	if (signal_ctrl_d((char *)shell->cmd_line, (*envp)) == TRUE)
		return (false);
	if (*shell->cmd_line && check_space_string((char *)shell->cmd_line))
	{
		add_history(shell->cmd_line);
		shell->tokens = lexer(shell->cmd_line);
		shell->b_tokens = shell->tokens;
		if (parser(&shell->tokens, &shell->parser))
		{
			shell->b_parser = shell->parser;
			expander(&shell->parser, (*envp));
			shell->parser = shell->b_parser;
			executor(&shell->parser, envp);
		}
		signal(SIGQUIT, SIG_IGN);
		shell->b_parser = shell->parser;
	}
	free_shell(shell);
	return (true);
}
