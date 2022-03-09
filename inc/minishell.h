/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 08:45:09 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/09 10:26:52 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "lexer.h"

typedef struct s_minishell {
	t_lexer	lexer;
}				t_minishell;

void	free_shell(t_minishell *shell);

#endif
