/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer_test.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/18 10:14:19 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/18 16:35:23 by sde-quai      ########   odam.nl         */
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
	free_lexer(tokens);
}

static void	test_1()
{
	test_setup("   testing    ");
	compare_tokens("testing", e_word);
}

static void	test_2()
{
	test_setup("  test   super test          meeee!");
	compare_tokens("test", e_word);
	compare_tokens("super", e_word);
	compare_tokens("test", e_word);
	compare_tokens("meeee!", e_word);
}

static void	test_3()
{
	test_setup("  echo   test\"\'d_commmas\"         | cat -e");
	compare_tokens("echo", e_word);
	compare_tokens("test", e_word);
	compare_tokens("\"\'d_commmas\"", e_word);
	compare_tokens("|", pipe);
	compare_tokens("cat", e_word);
	compare_tokens("-e", e_word);
}

static void test_4()
{
	test_setup("  echo   test\'\"s_commmas\'         | cat -e");
	compare_tokens("echo", e_word);
	compare_tokens("test", e_word);
	compare_tokens("\'\"s_commmas\'", e_word);
	compare_tokens("|", pipe);
	compare_tokens("cat", e_word);
	compare_tokens("-e", e_word);
}

static void test_5()
{
	test_setup("echo \'$HOME\"\"\"\'    >test.txt");
	compare_tokens("echo", e_word);
	compare_tokens("\'$HOME\"\"\"\'", e_word);
	compare_tokens(">", e_s_out);
	compare_tokens("test.txt", e_word);	
}

static void test_6()
{
	test_setup("ls <<>>><> || \"cat -e\"       cookies");
	compare_tokens("ls", e_word);
	compare_tokens("<<", e_d_in);
	compare_tokens(">>", e_d_out);
	compare_tokens("<", e_s_in);
	compare_tokens(">", e_s_out);
	compare_tokens("|", pipe);
	compare_tokens("|", pipe);
	compare_tokens("\"cat -e\"", e_word);
	compare_tokens("cookies", e_word);
}

static void test_7()
{
	test_setup(" \"HELLO\"  \"HELLO\"\'WORLD\' ");
	compare_tokens("\"HELLO\"", e_word);
	compare_tokens("\"HELLO\"", e_word);
	compare_tokens("\'WORLD\'", e_word);
}

static void test_8()
{
	test_setup("echo \"$HOME\'\'\'\"    >test.txt");
	compare_tokens("echo", e_word);
	compare_tokens("\"$HOME\'\'\'\"", e_word);
	compare_tokens(">", e_red_out_trunc);
	compare_tokens("test.txt", e_word);	
}

static void test_9()
{
	test_setup("funny\"test\'\'\'\" || >> hi << test.txt");
	compare_tokens("funny\"test\'\'\'\"", e_word);
	compare_tokens("|", pipe);
	compare_tokens("|", pipe);
	compare_tokens(">>", e_d_out);
	compare_tokens("hi", e_word);
	compare_tokens("<<", e_d_in);
	compare_tokens("test.txt", e_word);
}

static void test_10()
{
	test_setup("cat | ls >>> < < >> << | echo HELLOOO world");
	compare_tokens("cat", e_word);
	compare_tokens("|", pipe);
	compare_tokens("cls", e_word);
	compare_tokens(">>", e_d_out);
	compare_tokens(">", e_s_out);
	compare_tokens("<", e_s_in);
	compare_tokens("<", e_s_in);
	compare_tokens(">>", e_d_out);
	compare_tokens("<<", e_d_in);
	compare_tokens("echo", e_word);
	compare_tokens("HELLOOO", e_word);
	compare_tokens("world", e_word);
}


int test_lexer(void)
{
	UNITY_BEGIN();
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
	test_7();
	test_8();
	test_9();
	test_10();
	return (UNITY_END());
}