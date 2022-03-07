/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 09:49:07 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/03 14:55:53 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief null terminates the last char * allocated in the 2d array with NULL
 * 
 * @param cmd1_2d 2d array
 */
static void	ft_split_null_termininate(char **cmd1_2d)
{
	int	i;

	i = 0;
	while (cmd1_2d[i])
		i++;
	cmd1_2d[i] = NULL;
}

/**
 * @brief Checks for every command in the possible paths for the given
 * command.
 * 
 * @param cmd cmd that needs to be found
 * @param paths where the paths are placed inside a 2d char aray
 * @return char* with the right command path or NULL if command not found
 */
static char	*get_command(char *cmd, char **paths)
{
	char	*path_cmd;
	char	*tmp;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		ft_check_malloc(tmp);
		path_cmd = ft_strjoin(tmp, cmd);
		ft_check_malloc(path_cmd);
		free(tmp);
		if (!access(path_cmd, F_OK))
			return (path_cmd);
		free(path_cmd);
		paths++;
	}
	return (NULL);
}

/**
 * @brief Get the array 2d from direct path
 * 
 * @param cmd_path direct path
 * @return char** the cmd in 2d array with NULL in the last char *
 */
static char	**get_array_2d_from_direct_path(char *cmd_path)
{
	char	*cmd;	
	char	**cmd_2d;

	cmd = ft_strrchr(cmd_path, '/');
	cmd_2d = ft_split(cmd, ' ');
	ft_check_malloc(cmd_2d);
	ft_split_null_termininate(cmd_2d);
	return (cmd_2d);
}

/**
 * @brief Get the direct path and remove after the first ' '
 * 
 * @param cmd 
 * @return char* returns the direct path
 */
static char	*get_direct_path(char *cmd)
{
	char	*direct_path;

	direct_path = ft_strdup_c(cmd, ' ');
	ft_check_malloc(direct_path);
	return (direct_path);
}

/**
 * @brief executes the cmd given in the cmd variable and checks for 
 * direct paths and in the directories where the commands are found. 
 * 
 * @param cmd command that needs to be executed in char *
 * @param paths paths struct
 */
void	execute_execve(char *cmd, t_envp *paths)
{
	char	**cmd_2d;
	char	*cmd_path;
	char	*direct_path;

	direct_path = get_direct_path(cmd);
	if (!access(direct_path, F_OK))
	{
		cmd_path = direct_path;
		cmd_2d = get_array_2d_from_direct_path(cmd);
	}
	else
	{
		cmd_2d = ft_split(cmd, ' ');
		ft_check_malloc(cmd_2d);
		ft_split_null_termininate(cmd_2d);
		cmd_path = get_command(cmd_2d[0], paths->paths_2d);
	}
	if (execve(cmd_path, cmd_2d, paths->envp) < 0)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	free(cmd_path);
	ft_split_free(cmd_2d);
}
