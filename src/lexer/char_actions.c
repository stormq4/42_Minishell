/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   char_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/10 11:54:22 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/06/10 11:56:07 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/**
 * @brief finds the minimum length in one of the special
 * charachters given below
 * 
 * @param cmd_line prompted command line
 * @param i incrementer of the string
 * @return size_t smallest value of earliest special charachter
 * int string
 */
size_t	find_min_char(const char *cmd_line, size_t *i)
{
	size_t	j_n[6];
	size_t	j;

	j_n[0] = ft_strlen_c(&cmd_line[*i], space);
	j_n[1] = ft_strlen_c(&cmd_line[*i], s_quote);
	j_n[2] = ft_strlen_c(&cmd_line[*i], d_quote);
	j_n[3] = ft_strlen_c(&cmd_line[*i], red_in);
	j_n[4] = ft_strlen_c(&cmd_line[*i], red_out);
	j_n[5] = ft_strlen_c(&cmd_line[*i], c_pipe);
	j = find_min_size_t(j_n, 6);
	return (j);
}

/**
 * @brief checks belongs to a word
 * 
 * @param str_i 
 * @return int 
 */
int	check_char_for_word(char str_i)
{
	if (str_i == space)
		return (false);
	else if (str_i == c_pipe)
		return (false);
	else if (str_i == red_in)
		return (false);
	else if (str_i == red_out)
		return (false);
	else if (!str_i)
		return (false);
	return (true);
}
