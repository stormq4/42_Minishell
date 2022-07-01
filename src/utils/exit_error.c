/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_error.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 08:49:37 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/10 15:11:08 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_error_message(char	*message)
{
	ft_putstr_fd("minishell: ", 2);
	perror(message);
	g_error = errno;
	exit(errno);
}
