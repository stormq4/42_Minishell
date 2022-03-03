/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 15:26:58 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/03 14:20:06 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Finds int the enviroment variable the paths of the commands
 * 
 * @param env 2d char array where one holds the paths of the executables
 * @return char* the string where the paths are found
 */
static char	*find_paths(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

/**
 * @brief redirects the file descriptors to the last pipe.
 * a loop is used to pass fd as the file descriptor in end[0].
 * At the end of the pipe the filedescriptor is used of the 
 * output file.
 * 
 * @param p struct for storing information of the file descriptors 
 * of the files and buffer file descriptor nr of arguments and 
 * @param argv 
 * @param paths enviroment paths are stored here for execution 
 */
static void	pipex(t_pipex *p, char **argv, t_envp *paths)
{
	p->fd = p->f1;
	while (p->cmd_count < p->max_cmd - 1)
	{
		p->fd = fork_pipe(p, argv[p->cmd_count], paths, -1);
		p->cmd_count++;
	}
	p->fd = fork_pipe(p, argv[p->cmd_count], paths, p->f2);
	close(p->fd);
}

/**
 * @brief starting point of pipex executable. This program reanacts the Pipe |
 * functionality. And is executed like this --> ./pipex file1 cmd1 cmd2 file2
 * 
 * @param argc argument count
 * @param argv argument variables
 * @param envp enviroment variables
 * @return int to the computer for succes or error
 */
int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;
	t_envp	paths;

	p.f1 = open(argv[1], O_RDONLY);
	p.f2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	p.cmd_count = 2;
	p.max_cmd = argc - 1;
	if (p.f1 < 0 || p.f1 > OPEN_MAX || p.f2 < 0 || p.f2 > OPEN_MAX)
	{
		perror("");
		exit(errno);
	}
	paths.envp = envp;
	paths.paths_2d = ft_split(find_paths(envp), ':');
	ft_check_malloc(paths.paths_2d);
	pipex(&p, argv, &paths);
	ft_split_free(paths.paths_2d);
	return (0);
}
