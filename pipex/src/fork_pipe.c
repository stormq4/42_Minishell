/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_pipe.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/21 10:46:01 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/03 14:42:18 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief checks for the end of the set of pipes and writes to the
 * file descriptor of file2 if at the end. If not at the end it 
 * writes to end[1]
 * 
 * @param end pipe of filedescriptors
 * @param flag file descriptor of file2 or not 
 */
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

/**
 * @brief The child writes to the file descriptor 
 * p->fd from the stdin and then the stdout to the end[1] pipe and executes
 * the command.
 * 
 * @param end the pipe of fd's
 * @param p pipex struct
 * @param flag to check for end of pipe
 */
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

/**
 * @brief The parent writes to the end[0] which is returned to the 
 * fd. It waits for the child to be finished.
 * 
 * @param child pid_t variable of the child process
 * @param end is the pipe of file descriptors
 * @param p pipex struct
 */
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

/**
 * @brief Creates a fork where two different processes are run at once
 * namely the parent and the child. The child writes to the file descriptor 
 * p->fd from the stdin and then the stdout to the end[1] pipe and executes
 * the command. The parent writes to the end[0] which is returned to the 
 * fd.
 * 
 * @param p pipex struct
 * @param cmd command in char* that needs to be executed
 * @param paths possible paths of the cmd
 * @param flag for the end of the pipe
 * @return int which is the file descriptor of end[0]
 */
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
