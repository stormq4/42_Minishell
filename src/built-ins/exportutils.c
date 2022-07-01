/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exportutils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 15:47:48 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/06/28 13:46:41 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int	is_valid_identifier(char *s)
{
	if (ft_strlen(s) - ft_strlen(ft_strchr(s, '=')) == 0 && *s == '=')
		return (false);
	return (true);
}

void	free_split_arr(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free (split);
}

int	print_export(char **envp)
{
	int	i;
	int	j;
	int	open;

	i = -1;
	while (envp[++i])
	{
		j = -1;
		open = 0;
		printf("declare -x ");
		while (envp[i][++j])
		{
			if (open == 0 && envp[i][j] == '=')
			{
				printf("%c", envp[i][j]);
				printf("\"");
				open = 1;
				continue ;
			}
			printf("%c", envp[i][j]);
		}
		printf("\"");
		printf("\n");
	}
	return (EXIT_SUCCESS);
}

t_bool	mult_export(char *cmdline, char ***env)
{
	mini_export(cmdline, env);
	exit(g_error);
}
