/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:25:03 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/07 15:14:12 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "utils.h"

typedef enum e_token_type {
	e_word,
	e_pipe,
	e_red_in,
	e_red_out_trunc,
	e_red_out_append,
	e_red_heredoc
}			t_token_type;

typedef	struct s_token {
	size_t			token_id;
	char			*token_data;
	t_token_type	type;
}				t_token;

typedef struct s_lexer
{
	const char	*cmd_line;
	size_t		token_nr;
	t_token		*tokens;
}				t_lexer;

void	lexer(t_lexer *lexer);

#endif
