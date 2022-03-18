/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:25:03 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/18 16:36:47 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "utils.h"

/**
 * @brief enum for types of token to categorize them
 * 
 */
typedef enum e_token_type {
	e_word,
	e_pipe,
	e_s_in,
	e_d_in,
	e_s_out,
	e_d_out,
	e_red_in,
	e_red_out_trunc,
	e_red_out_append,
	e_red_heredoc
}			t_token_type;

/**
 * @brief token struct in a link list
 * 
 * @param token_id starting from 0 in ascending order
 * @param token_data char * string of the partial cmd line
 * @param type enum for type of token
 * @param next points to the next s_token struct
 */
typedef struct s_token {
	size_t			token_id;
	char			*token_data;
	t_token_type	type;
	struct s_token	*next;
}				t_token;

/**
 * @brief lexer struct which holds the data of the lexer
 * 
 * @param cmd_line line read from the command line
 * @param token_nr total number of tokens
 */
typedef struct s_lexer
{
	char	*cmd_line;
	size_t	token_nr;
	t_token	*tokens;
}				t_lexer;

// lexer.c
t_lexer	*lexer(t_lexer *lexer);

// lexer_lst.c
t_token	*lexer_lstnew(void);
void	lexer_lstadd_back(t_token **lst, t_token *new);
void	lexer_lstclear(t_token **lst);

// categorize_words.c
void	find_next_quote(t_lexer *lexer, size_t *i, t_character quote);
void	find_next_space(t_lexer *lexer, size_t *i);

// categorize_pipes.c
void	categorize_pipe(t_lexer *lexer);

// categorize_redirects.c
void	categorize_redirects(t_lexer *lexer, size_t *i, t_character red);

#endif
