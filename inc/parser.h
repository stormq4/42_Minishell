/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 09:27:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/15 14:27:05 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

/**
 * @brief t_red struct
 * 
 * @param fd file descriptor
 * @param type of token
 * @param file filename
 */
typedef struct s_red {
	int				fd;
	t_token_type	type;
	char			*file;
}				t_red;

/**
 * @brief t_exec struct
 * 
 * @param cmd command to be executed
 * @param args containing the NULL terminated splitted arguments
 */
typedef struct s_exec {
	char	*cmd;
}				t_exec;

/**
 * @brief t_command struct
 * 
 * @param in input redirects in a t_list
 * @param out output redirects in a t_list
 * @param t_exec struct 
 */
typedef struct s_command {
	t_list	*in;
	t_list	*out;
	t_exec	*exec;
}				t_command;

// parser.c
t_bool	parser(t_list **token_lst, t_list **b_lst);

// parser_delete.c
void	parser_delete(void *ct);

// append_redirect.c
t_bool	append_redirect(t_list **token_lst, t_command *command, \
t_token *token);

// append_word.c
void	append_word(t_list **token_lst, t_command *command, t_token *token);

#endif
