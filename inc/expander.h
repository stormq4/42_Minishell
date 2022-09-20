/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:57:08 by gpirro            #+#    #+#             */
/*   Updated: 2022/09/16 18:03:26 by gianlucapir      ###   ########.fr       */
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
int		find_len_until_special_char(char *var);
t_list	*special_expand_order(char *var);
int		env_in_special(char *str, char **envp);
t_bool	has_special_expand_char(char *str);
char	*replace_special_var(char *str, char **envp);
t_bool	check_special_expand(char a);
char	*order_lst_join(t_list	**order);
void	free_order_lst(t_list *order);

#endif
