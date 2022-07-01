/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expander.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/16 12:57:08 by gpirro        #+#    #+#                 */
/*   Updated: 2022/06/28 10:36:51 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <minishell.h>
# include <stdbool.h>

typedef struct s_expand
{
	char	*split;
	int		expand;
	int		closed;
}	t_expand;

bool	replace_var_or_not(char *line);
char	*trimmer(char *str);
void	expander(t_list **cmd_list, char **envp);
char	*remove_remainders(char *line);
char	*replace_env_var(char *str, char **envp);
int		replace_env_var_in_lst(t_list **split, char **envp);
char	*bef_env_var(char *str);
char	*aft_env_var(char *str);
char	*lst_join(t_list **split);
void	expand_exec(t_exec *exec, char **envp);
int		split_input(t_list **split, char *line);
void	replace(char **line, char **envp);
int		add_space(t_list **split);
int		split_item(char **line, t_list **split);
int		replace_g_error_in_lst(t_list **split);
void	free_split(t_list **lstsplit);

#endif
