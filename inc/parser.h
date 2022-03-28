/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 09:27:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/28 15:17:18 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

typedef struct s_red {
	int				fd;
	t_token_type	type;
	const char		*file;
}				t_red;

typedef struct s_exec {
	const char	*cmd;
	char		**args;
}				t_exec;

typedef struct s_command {
	t_list	*in;
	t_list	*out;
	t_list	*heredoc;
	t_exec	*exec;
}				t_command;

t_list	*parser(t_list **token_lst);

void	parser_delete(void *ct);

#endif