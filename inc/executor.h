/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 11:11:52 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/29 17:40:01 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser.h"
# include "builtins.h"

typedef enum e_pipelang {
	p_child = 0,
	p_read = 0,
	p_write = 1
}				t_pipelang;

typedef struct s_pipex {
	int		fd;
	int		cmd_count;
	int		max_cmd;
	t_list	*fork_lst;
	char	**paths_2d;
	char	***envp;
}				t_pipex;

// executor.c
void	executor(t_list **cmd_lst, char ***envp);

// heredoc.c
int		prompt_for_heredoc(t_red *red);

// in_out_fd.c
void	find_last_output_fd(t_list **out, int fd);
void	find_last_input_fd(t_list **in, int fd);

// execute_cmd.c
void	execute_execve(char *cmd, t_pipex *p);

// forks.c
pid_t	*fork_id(void);
void	remove_fork_list(t_list **fork_lst);
void	wait_for_fork(pid_t fork_id);

#endif
