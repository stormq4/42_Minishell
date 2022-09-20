/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:02:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/07/01 14:34:11 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * @brief The parent process waits for the child process to be finished
 * 
 * @param fork_id 
 */
void	wait_for_fork(pid_t fork_id)
{
	int	status;

	if (waitpid(fork_id, &status, 0) < 0)
		exit_error_message("");
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	g_error = status;
}

/**
 * @brief the pid_t of the forks are directed ot wait_for_fork funciton.
 * The function frees the malloced pid_t * and the list itself afterwards.
 * 
 * @param fork_lst 
 */
void	remove_fork_list(t_list **fork_lst)
{
	t_list	*forks;
	t_list	*tmp;

	forks = *fork_lst;
	while (forks)
	{
		tmp = forks;
		wait_for_fork(*(pid_t *)(tmp->ct));
		free(forks->ct);
		forks = forks->next;
		free(tmp);
	}
}

/**
 * @brief mallocs a pid_t * for in the t_list of forks
 * 
 * @return pid_t* 
 */
pid_t	*fork_id(void)
{
	pid_t	*fork_pid;

	fork_pid = malloc(sizeof(pid_t));
	ft_check_malloc(fork_pid);
	return (fork_pid);
}
