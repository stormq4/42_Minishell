/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 08:45:09 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/07 13:38:17 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include "libft.h"
# include "lexer.h"

// misschien een utils folder aanmaken met dit erin


typedef struct s_minishell {
	t_lexer	*lexer;
}				t_minishell;

#endif
