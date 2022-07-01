/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:28:15 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/24 11:47:14 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

t_bool	mini_pwd(void)
{
	char	pwd[PATH_MAX];

	if (getcwd(pwd, PATH_MAX))
		ft_putendl_fd(pwd, 1);
	else
		exit_error_message("");
	g_error = 0;
	exit(g_error);
	return (true);
}
