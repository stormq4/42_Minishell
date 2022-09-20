/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 13:36:11 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/19 17:05:07 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// necessary libraries
# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <limits.h>

extern int	g_error;

/**
 * @brief enum for boolean
 * 
 */
typedef enum e_bool {
	false,
	true
}			t_bool;

/**
 * @brief enum for assigning ascii values to characters
 * 
 */
typedef enum e_character {
	s_quote = 39,
	d_quote = 34,
	space = 32,
	c_pipe = 124,
	red_in = 60,
	red_out = 62
}			t_character;

// ft_strlen_c.c
size_t	ft_strlen_c(const char *str, int c);

// ft_strdup_len.c
char	*ft_strdup_len(const char *str, size_t len);

// find_min.c
size_t	find_min_size_t(size_t *nr_arr, size_t len);

// ft_lstlen.c
int		ft_lstlen(t_list *lst);

// exit_error.c
void	exit_error_message(char	*message);
void	exit_error_message_nr(char	*message, int nr);

// find_paths.c
char	*find_paths(char **env);

// signals.c
void	signal_ctrl_c(int sig);
t_bool	signal_ctrl_d(char *str, char **env);
t_bool	check_space_string(char *str);
void	signal_quit(int sig);
void	signal_ctrl_heredoc(int sig);

// find_shlvl.c
void	adjust_shlvl(char **env, t_bool increment);
char	*find_shlvl(char **env);
t_bool	shlvl_exists(char **env);

// malloc_env.c
char	**malloc_env(char **env);

// adjust_location.c
void	adjust_location(char **env);

// expander_utils.c
void	*pmalloc(size_t	size);
int		is_split_c(char c);
void	exit_error(char *msg, int exitcode);
t_bool	env_in_str(char *str, char **envp);
char	*find_env_var(char *str, char **envp);

// export_utils.c
void	export_var(char *var, char ***env, char **split);
int		split_var(char *var, char ***split);

#endif
