/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 08:45:45 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/25 10:31:33 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

t_token		*tokens;
t_command	*commands;

static void	test_setup(const char *cmd_line)
{
	tokens = lexer(cmd_line);
	commands = parser(&tokens);
	TEST_ASSERT_NOT_NULL(commands);
}
