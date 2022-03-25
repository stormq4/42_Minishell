/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 09:27:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/25 10:28:33 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

typedef struct s_exec {
	const char *cmd;
	const char **args;
	struct s_exec	*next;
}				t_exec;

typedef struct s_command {
	t_token				*input;
	t_token				*output;
	t_exec				*exec;
	struct s_command	*next;
}				t_command;

t_command	*parser(t_token **token_lst);

#endif