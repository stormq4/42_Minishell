/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_cmd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 16:58:21 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/19 15:48:36 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static char	*get_command(char *cmd, char **paths)
{
	char	*path_cmd;
	char	*tmp;

	if (!paths || !cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (NULL);
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

static t_bool	check_cmd_is_dir(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '/')
			return (true);
		cmd++;
	}
	return (false);
}

static void	execute_cmd(char *cmd_path, char **cmd_2d, char **paths)
{
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_2d[0], 2);
		if (check_cmd_is_dir(cmd_2d[0]))
			ft_putstr_fd(": No such file or directory\n", 2);
		else
			ft_putstr_fd(": command not found\n", 2);
		g_error = 127;
		exit(127);
	}
	g_error = 0;
	if (execve(cmd_path, cmd_2d, paths) < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_2d[0], 2);
		if (check_cmd_is_dir(cmd_2d[0]))
			ft_putstr_fd(": No such file or directory\n", 2);
		else
			ft_putstr_fd(": command not found\n", 2);
		g_error = 127;
		exit(127);
	}
}

void	execute_execve(char *cmd, t_pipex *p)
{
	char	**cmd_2d;
	char	*cmd_path;

	cmd_path = NULL;
	cmd_2d = ft_split(cmd, ' ');
	ft_check_malloc(cmd_2d);
	ft_split_null_termininate(cmd_2d);
	if (!access(cmd_2d[0], F_OK))
	{
		cmd_path = ft_strdup(cmd_2d[0]);
		ft_split_free(cmd_2d);
		cmd_2d = get_array_2d_from_direct_path(cmd);
	}
	else
		cmd_path = get_command(cmd_2d[0], p->paths_2d);
	execute_cmd(cmd_path, cmd_2d, *p->envp);
}
