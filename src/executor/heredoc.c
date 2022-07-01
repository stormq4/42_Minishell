/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 11:01:59 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/10 13:44:29 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * @brief if a heredoc (<<) is found it prompts for the input
 * untill the value of the heredoc is given. This is put as input
 * for the next command.
 * 
 * @param red t_red struct
 * @return int file descriptor
 */
int	prompt_for_heredoc(t_red *red)
{
	int		end[2];
	char	*line;
	char	*n_line;

	if (pipe(end) < 0)
	{
		exit_error_message("");
		exit(errno);
	}
	while (true)
	{
		line = readline("> ");
		if (ft_strncmp(line, red->file, ft_strlen(red->file)) == 0)
		{
			free(line);
			break ;
		}
		n_line = ft_strjoin(line, "\n");
		free(line);
		write(end[1], n_line, ft_strlen(n_line));
		free(n_line);
	}
	close(end[1]);
	return (end[0]);
}
