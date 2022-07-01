/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 19:38:25 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/07/01 13:24:48 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "utils.h"
# include <limits.h>

// builtins.c
t_bool	all_builtins(char *cmd, char ***envp);
t_bool	check_clean_builtin(char *str, int size);
t_bool	single_cmd_builtins(char *cmd, char ***envp);

// pwd.c
t_bool	mini_pwd(void);

// mini_echo.c
t_bool	mini_echo(char *line);

// mini_env.c
t_bool	mini_env(char **env, char *cmd);

// mini_exit.c
t_bool	multiple_cmd_exit(char *cmd);
t_bool	single_cmd_exit(char *cmd);

// mini_unset
t_bool	mini_unset(char *cmdline, char ***env);
t_bool	mult_unset(char *cmd_line, char ***env);
int		unset_var(char *var, char ***env);

// cd_utils.c
t_bool	mult_cd(char *cmd, char ***envp);
t_bool	mini_cd(char *cmd, char ***envp);
t_bool	check_backslash(char *cmd);
char	*trim_backslash(char *trim);
char	*return_trimmed_cmd(char *cmd);
char	*plain_cd(void);
char	*relative_cd(char *cmd);

// export.c
t_bool	mini_export(char *cmdline, char ***env);
t_bool	mult_export(char *cmdline, char ***env);
void	free_split_arr(char **split);
int		is_valid_identifier(char *s);
int		print_export(char **envp);
int		split_var(char *var, char ***split);
void	export_var(char *var, char ***env, char **split);

#endif
