/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 10:14:19 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/18 11:58:16 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

t_tokens	*tokens;

static void	test_setup(const char	*cmd_line)
{
	tokens = lexer(line);
	TEST_ASSERT_NOT_NULL(tokens);
}

static void	compare_tokens(const char *test_string, t_token_type type)
{
	size_t	len;
	
	TEST_ASSERT_NOT_NULL(tokens);
	TEST_ASSERT_EQUAL_INT16(type, token->type);
	len = ft_strlen(token_data);
	TEST_ASSERT_EQUAL_STRING(test_string, tokens->token_data);
	TEST_ASSERT_EQUAL_INT64(len, ft_strlen(tokens->token_data));
	tokens = tokens->next;
}

void	setUP(void)
{
	
}

void	tearDown(void)
{

}

static void	test_1()
{
	test_setup("   testing    ");
	compare_tokens("testing", word);
}

static void	test_2()
{
	test_setup("  test   super test          meeee!");
	compare_tokens("test", word);
	compare_tokens("super", word);
	compare_tokens("test", word);
	compare_tokens("meeee!", word);
	
}

void test_lexer(void)
{
	
}