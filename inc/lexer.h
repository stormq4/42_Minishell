/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 17:25:03 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/10 11:55:58 by sde-quai      ########   odam.nl         */
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
	e_d_out
}			t_token_type;

/**
 * @brief token struct in a link list
 * 
 * @param token_data char * string of the partial cmd line
 * @param type enum for type of token
 */
typedef struct s_token {
	char			*token_data;
	t_token_type	type;
}				t_token;

// lexer.c
t_list	*lexer(const char *cmd_line);

// // lexer_lst.c
void	token_delete(void *ct);

// categorize_words.c
void	find_next_word(t_list **tokens, size_t *i, const char *cmd_line);

// categorize_pipes.c
void	categorize_pipe(t_list **tokens);

// categorize_redirects.c
void	categorize_redirects(t_list **tokens, size_t *i, t_character red, \
const char *cmd_line);

// char_actions.c
int		check_char_for_word(char str_i);
size_t	find_min_char(const char *cmd_line, size_t *i);

#endif
