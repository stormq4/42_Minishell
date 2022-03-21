/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:11:32 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/21 15:03:11 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int		main(int argc, char **argv, char **envp)
{
	int	check;

	// setbuf(stdout, NULL);
	// setbuf(stderr, NULL);
	(void)argc;
	(void)argv;
	(void)envp;
	check = lexer_test();
	printf("#NR of tests in done in Lexer-->: %d\n", check);
	return (0);
}
