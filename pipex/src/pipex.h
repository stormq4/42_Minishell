/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 12:10:37 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/03 15:05:37 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include "../../libft/libft.h"
# include <sys/stat.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

/**
 * @brief struct to store values for the piping.
 * 
 * @param f1 is the file descriptor for the file from the input
 * @param f2 is the ifle descriptor for the file from te output file
 * @param cmd_count incrementer until max_cmd
 * @param max_cmd 
 * @param fd file descriptor for the buffer pipes
 */
typedef struct s_pipex {
	int	f1;
	int	f2;
	int	cmd_count;
	int	max_cmd;
	int	fd;
}				t_pipex;

/**
 * @brief struct to store file descriptor paths
 * 
 * @param envp are the envirmoment variables in char**
 * @param paths_2d paths from enviroment variables where commands can be found
 */
typedef struct s_envp {
	char	**envp;
	char	**paths_2d;
}				t_envp;

void	execute_execve(char *cmd, t_envp *paths);
int		fork_pipe(t_pipex *p, char *cmd, t_envp *envp, int flag);

#endif
