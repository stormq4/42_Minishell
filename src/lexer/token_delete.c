/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_delete.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/07 17:19:36 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/09 11:27:27 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief deletes the tokens in the list this function is called 
 * and passed in ft_lstclear
 * 
 * @param ct content of the list
 */
void	token_delete(void *ct)
{
	t_token	*tok;

	tok = (t_token *)ct;
	if (!tok)
		return ;
	if (tok->token_data)
		free(tok->token_data);
	free(tok);
}
