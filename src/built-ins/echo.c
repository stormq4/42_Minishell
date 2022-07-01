/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/13 15:09:06 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/06/28 13:44:07 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

static char	*trim_echo(char *line)
{
	char	*str;

	if (ft_strlen(line) == 4)
		str = line + 4;
	else
		str = line + 5;
	return (str);
}

static char	*trim_n(char *line, int *check)
{
	char	*str;
	int		i;

	i = 0;
	str = line;
	if (ft_strncmp(str, "-n", 2) == 0)
	{
		if (str[i] == '-')
			i++;
		i++;
		while (str[i] == 'n')
			i++;
		if (str[i] == ' ')
		{
			str = str + 1 + i;
			(*check) = 1;
			return (trim_n(str, check));
		}
		else if (!str[i])
			(*check) = 1;
		else if (str[i] != ' ')
			return (str);
		return (str + i);
	}
	return (str);
}

t_bool	mini_echo(char *line)
{
	char	*str;
	int		check;

	check = 0;
	str = trim_echo(line);
	str = trim_n(str, &check);
	if (check == 1)
		ft_putstr_fd(str, 1);
	else
	{
		str = ft_strjoin(str, "\n");
		ft_putstr_fd(str, 1);
		free(str);
	}
	g_error = 0;
	exit(g_error);
	return (true);
}
