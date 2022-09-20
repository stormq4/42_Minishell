/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   in_out_fd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 11:02:43 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/14 15:53:59 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/**
 * @brief redirects the pointer of the incomming file descriptor to 
 * the location of the stdin or stdout.
 * 
 * @param fd filedescriptor
 * @param in_out_fd stdin or stdout
 */
static void	dup2_in_out(int fd, int in_out_fd)
{
	if (dup2(fd, in_out_fd) < 0)
	{
		exit_error_message(" ");
	}
	close(fd);
}

/**
 * @brief finds opens and redirects the intput to the stdin in the 
 * child porcess
 * 
 * @param output t_list of output files
 * @param fd file descriptor of the current intput
 */
void	find_last_input_fd(t_list **input, int fd)
{
	t_red	*red;
	t_list	*in;

	in = *input;
	red = (t_red *)in->ct;
	while (red->file)
	{
		if (fd != STDIN_FILENO)
			close(fd);
		if (red->type == e_d_in)
			fd = prompt_for_heredoc(red);
		else if (red->type == e_s_in)
			fd = open(red->file, O_RDONLY);
		if (fd < 0 || fd > OPEN_MAX)
			exit_error_message_nr(red->file, 1);
		in = in->next;
		if (in)
			red = (t_red *)in->ct;
		else
			break ;
	}
	if (fd != STDIN_FILENO)
		dup2_in_out(fd, STDIN_FILENO);
}

/**
 * @brief finds opens and redirects the output to the stdout in the 
 * child porcess
 * 
 * @param output t_list of output files
 * @param fd file descriptor of the current output
 */
void	find_last_output_fd(t_list **output, int fd)
{
	t_red	*red;
	t_list	*out;

	out = *output;
	red = (t_red *)out->ct;
	while (red->file)
	{
		if (fd != STDOUT_FILENO)
			close(fd);
		if (red->type == e_s_out)
			fd = open(red->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (red->type == e_d_out)
			fd = open(red->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd < 0 || fd > OPEN_MAX)
			exit_error_message(red->file);
		out = out->next;
		if (out)
			red = (t_red *)out->ct;
		else
			break ;
	}
	if (fd != STDOUT_FILENO)
		dup2_in_out(fd, STDOUT_FILENO);
}
