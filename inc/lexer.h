/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:25:03 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/25 15:03:28 by sde-quai      ########   odam.nl         */
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
}			t_token_type;

/**
 * @brief token struct in a link list
 * 
 * @param token_data char * string of the partial cmd line
 * @param type enum for type of token
 * @param next points to the next s_token struct
 */
typedef struct s_token {
	char			*token_data;
	t_token_type	type;
	// struct s_token	*next;
}				t_token;

// lexer.c
t_list	*lexer(const char *cmd_line);

// // lexer_lst.c
void	token_delete(void *ct);
// t_token	*lexer_lstnew(void);
// void	lexer_lstadd_back(t_token **lst, t_token *new);
// void	lexer_lstclear(t_token **lst);

// categorize_words.c
void	find_next_quote(t_list **tokens, size_t *i, t_character quote, \
const char *cmd_line);
void	find_next_word(t_list **tokens, size_t *i, const char *cmd_line);

// categorize_pipes.c
void	categorize_pipe(t_list **tokens);

// categorize_redirects.c
void	categorize_redirects(t_list **tokens, size_t *i, t_character red, \
const char *cmd_line);

#endif
