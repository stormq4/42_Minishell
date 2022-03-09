/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:25:03 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 09:56:54 by sde-quai      ########   odam.nl         */
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

typedef struct s_token {
	size_t			token_id;
	char			*token_data;
	t_token_type	type;
	struct s_token	*next;
}				t_token;

typedef struct s_lexer
{
	char	*cmd_line;
	size_t	token_nr;
	t_token	*tokens;
}				t_lexer;

// lexer.c
void	lexer(t_lexer *lexer);

// lexer_lst.c
t_token	*lexer_lstnew(void);
void	lexer_lstadd_back(t_token **lst, t_token *new);
void	lexer_lstclear(t_token **lst);

// categorize_words.c
void	find_next_quote(t_lexer *lexer, size_t *i, t_character quote);
void	find_next_space(t_lexer *lexer, size_t *i);

// categorize_pipes.c
void	categorize_pipe(t_lexer *lexer, size_t *i);

// categorize_redirects.c
void	categorize_redirects(t_lexer *lexer, size_t *i, t_character red);

#endif
