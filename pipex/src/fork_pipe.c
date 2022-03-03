/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_pipe.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/21 10:46:01 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/01/31 14:45:52 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_end_pipe(int *end, int flag)
{
	if (flag != -1)
	{
		if (dup2(flag, STDOUT_FILENO) < 0)
		{
			perror("");
			exit(errno);
		}
		close(flag);
	}
	else
	{
		if (dup2(end[1], STDOUT_FILENO) < 0)
		{
			perror("");
			exit(errno);
		}
		close(end[1]);
	}
}

static void	pipex_child(int *end, t_pipex *p, int flag)
{
	if (dup2(p->fd, STDIN_FILENO) < 0)
	{
		perror("");
		exit(errno);
	}
	close(p->fd);
	check_end_pipe(end, flag);
	close(end[0]);
}

static void	pipex_parent(pid_t child, int *end, t_pipex *p)
{
	int	status;

	close(end[1]);
	if (dup2(end[0], STDIN_FILENO) < 0)
	{
		perror("");
		exit(errno);
	}
	waitpid(child, &status, 0);
	if (WIFEXITED(status) && p->cmd_count == p->max_cmd - 1)
		exit(WEXITSTATUS(status));
}

int	fork_pipe(t_pipex *p, char *cmd, t_envp *paths, int flag)
{
	int		end[2];
	pid_t	child;

	pipe(end);
	if (pipe(end) < 0)
	{
		perror("");
		exit(errno);
	}
	child = fork();
	if (child < 0)
	{
		perror("");
		exit(errno);
	}
	if (child == 0)
	{
		pipex_child(end, p, flag);
		execute_execve(cmd, paths);
	}
	else
		pipex_parent(child, end, p);
	return (end[0]);
}
