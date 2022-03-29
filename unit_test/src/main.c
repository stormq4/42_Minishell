/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 10:11:32 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/29 13:31:32 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int		main(int argc, char **argv, char **envp)
{
	int	nr_fails;

	(void)argc;
	(void)argv;
	(void)envp;
	nr_fails = lexer_test();
	printf("#NR of failes in lexer -->: %d\n", nr_fails);
	nr_fails = parser_test();
	printf("#NR of failes in parser -->: %d\n", nr_fails);

	return (0);
}
