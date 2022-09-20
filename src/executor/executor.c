/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 11:11:25 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/19 17:04:42 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * @brief Child process writes the executed command to write end of the
 * pipe, while redirecting the input and output if neccesary.
 * 
 * @param command t_command struct
 * @param end piped int[2]
 * @param p t_pipex struct
 */
static void	child_process(t_command *command, int *end, t_pipex *p, \
char **envp)
{
	close(end[p_read]);
	signal(SIGINT, signal_ctrl_heredoc);
	find_last_input_fd(&command->in, p->fd);
	if (p->cmd_count == p->max_cmd - 1)
	{
		close(end[p_write]);
		find_last_output_fd(&command->out, STDOUT_FILENO);
	}
	else
		find_last_output_fd(&command->out, end[p_write]);
	signal(SIGINT, signal_ctrl_c);
	if (!all_builtins(command->exec->cmd, &envp))
		execute_execve(command->exec->cmd, p);
}

/**
 * @brief pipe is initialized and forked short after. The child process is called
 * and the parent process closes the rest the write end and the input fd.
 * 
 * @param fork_id malloced fork_id to store a pid_t value
 * @param command t_command struct
 * @param p t_pipex struct
 * @return int 
 */
int	start_pipe(pid_t *fork_id, t_command *command, t_pipex *p, char **envp)
{
	int	end[2];

	if (pipe(end) < 0)
		exit_error_message("");
	*fork_id = fork();
	if (*fork_id < 0)
		exit_error_message("");
	else if (*fork_id == p_child)
		child_process(command, end, p, envp);
	else
	{
		if (p->fd != STDIN_FILENO)
			close(p->fd);
		close(end[p_write]);
	}
	return (end[p_read]);
}

/**
 * @brief Set the up pipe for every command and passes the fd to the next 
 * pipe. Forks are stored in a list where the content contains a pid_t * 
 * value. And rejoined and freed after being used.
 * 
 * @param p t_pipex struct
 * @param cmd_lst t_list of commands
 */
static void	set_up_pipe(t_pipex *p, t_list *cmd_lst, char ***envp)
{
	t_command	*command;
	t_list		*new_fork;

	p->fd = 0;
	command = (t_command *)cmd_lst->ct;
	while (true)
	{
		new_fork = ft_lstnew(fork_id());
		ft_lstadd_back(&p->fork_lst, new_fork);
		p->fd = start_pipe((pid_t *)new_fork->ct, command, p, *envp);
		cmd_lst = cmd_lst->next;
		if (!cmd_lst)
			break ;
		command = (t_command *)cmd_lst->ct;
		p->cmd_count++;
	}
	if (p->fd != STDIN_FILENO | p->fd != STDOUT_FILENO)
		close(p->fd);
	remove_fork_list(&p->fork_lst);
}

/**
 * @brief if there is no pipe in the command line this function is called
 * and the command is executed.
 * 
 * @param command t_command struct that contains all the data
 * @param p t_pipex struct
 */
static void	single_command(t_command *command, t_pipex *p, char ***envp)
{
	pid_t	fork_pid;
	t_bool	cmd_check;

	cmd_check = false;
	if (command->exec->cmd && single_cmd_builtins_check(command->exec->cmd))
		cmd_check = true;
	fork_pid = fork();
	if (fork_pid < 0)
		exit_error_message("");
	if (fork_pid == 0)
	{
		signal(SIGINT, signal_ctrl_heredoc);
		find_last_input_fd(&command->in, STDIN_FILENO);
		find_last_output_fd(&command->out, STDOUT_FILENO);
		if (cmd_check)
			exit(g_error);
		signal(SIGINT, signal_ctrl_c);
		if (!all_builtins(command->exec->cmd, envp))
			execute_execve(command->exec->cmd, p);
	}
	wait_for_fork(fork_pid);
	if (command->exec->cmd)
		single_cmd_builtins(command->exec->cmd, envp);
}

/**
 * @brief the executor gets a cmd_lst between for every command between the 
 * pipes and executes it.
 * 
 * @param cmd_lst t_list containing a t_command struct in its ct member
 * @param envp enviroment variables
 */
void	executor(t_list **cmd_lst, char ***envp)
{
	t_pipex		p;
	t_command	*command;
	char		*paths;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, signal_quit);
	paths = find_paths(*envp);
	if (paths)
		p.paths_2d = ft_split(paths, ':');
	else
		p.paths_2d = NULL;
	p.envp = envp;
	p.fork_lst = NULL;
	p.cmd_count = 0;
	p.max_cmd = ft_lstlen(*cmd_lst);
	command = (t_command *)(*cmd_lst)->ct;
	if (p.max_cmd == 1)
		single_command(command, &p, envp);
	else
		set_up_pipe(&p, *cmd_lst, envp);
	if (p.paths_2d)
		ft_split_free(p.paths_2d);
	signal(SIGINT, signal_ctrl_c);
}
