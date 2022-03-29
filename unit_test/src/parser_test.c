/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_test.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 08:45:45 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/03/29 13:33:55 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

t_list		*tokens;
t_list		*commands;
t_list		*bc;
t_command	*cmd;

static void	test_setup(const char *cmd_line)
{
	tokens = lexer(cmd_line);
	TEST_ASSERT_NOT_NULL(tokens);
	commands = parser(&tokens);
	bc = commands;
	TEST_ASSERT_NOT_NULL(commands);
}

static void	compare_in(t_list **in, const char *test_string, t_token_type type)
{
	t_red	*input;
	size_t	len;

	input = (t_red *)(*in)->ct;
	if (!input)
	{
		printf("No new token found");
		TEST_ABORT();
		return ;
	}
	TEST_ASSERT_EQUAL_INT16(type, input->type);
	TEST_ASSERT_EQUAL_STRING(test_string, input->file);
	len = ft_strlen(input->file);
	TEST_ASSERT_EQUAL_UINT64(len, ft_strlen(test_string));
	(*in) = (*in)->next;
}

static void	compare_out(t_list **out, const char *test_string, t_token_type type)
{
	t_red	*output;
	size_t	len;

	output = (t_red *)(*out)->ct;
	if (!output)
	{
		printf("No new token found");
		TEST_ABORT();
		return ;
	}
	TEST_ASSERT_EQUAL_INT16(type, output->type);
	TEST_ASSERT_EQUAL_STRING(test_string, output->file);
	len = ft_strlen(output->file);
	TEST_ASSERT_EQUAL_UINT64(len, ft_strlen(test_string));
	(*out) = (*out)->next;
}

static void	compare_heredoc(t_list **hd, const char *test_string, t_token_type type)
{
	t_red	*heredoc;
	size_t	len;

	heredoc = (t_red *)(*hd)->ct;
	if (!heredoc)
	{
		printf("No new token found");
		TEST_ABORT();
		return ;
	}
	TEST_ASSERT_EQUAL_INT16(type, heredoc->type);
	TEST_ASSERT_EQUAL_STRING(test_string, heredoc->file);
	len = ft_strlen(heredoc->file);
	TEST_ASSERT_EQUAL_UINT64(len, ft_strlen(test_string));
	(*hd) = (*hd)->next;
}

static void	compare_exec(t_exec *exec, const char *test_string)
{
	char	**tstring_2d;
	int		len_2d;

	TEST_ASSERT_EQUAL_STRING(test_string, exec->cmd);
	tstring_2d = ft_split(test_string, ' ');
	ft_split_null_termininate(tstring_2d);
	len_2d = ft_split_len(exec->args);
	TEST_ASSERT_EQUAL_INT16(ft_split_len(tstring_2d), len_2d);
	TEST_ASSERT_EQUAL_STRING_ARRAY(tstring_2d, exec->args, len_2d);
}

void	setUp(void) {}

void	tearDown(void)
{
	ft_lstclear(&tokens, token_delete);
	ft_lstclear(&bc, parser_delete);
	tokens = NULL;
	commands = NULL;
	bc = NULL;
}

void	test_1()
{
	test_setup("< maan         test     ");
	cmd = (t_command *)commands->ct;
	compare_in(&cmd->in, "maan", e_s_in);
	compare_exec(cmd->exec, "test");
}

void	test_2()
{
	test_setup("<< lekker ls| cat  >j >> grappig");
	cmd = (t_command *)commands->ct;
	compare_heredoc(&cmd->heredoc, "lekker", e_d_in);
	compare_exec(cmd->exec, "ls");
	commands++;
	cmd = (t_command *)commands->ct;
	compare_exec(cmd->exec, "cat");
	compare_out(&cmd->out, "j", e_s_out);
	compare_out(&cmd->out, "grappig", e_d_out);
}

void	test_3()
{
	test_setup("cat | ls <in >>out >out1| cat -e");
	cmd = (t_command *)commands->ct;
	compare_exec(cmd->exec, "cat");
	commands++;
	cmd = (t_command *)commands->ct;
	compare_in(&cmd->in, "in", e_s_in);
	compare_out(&cmd->out, "out", e_d_out);
	compare_out(&cmd->out, "out1", e_s_out);
	compare_exec(cmd->exec, "ls");
	commands++;
	cmd = (t_command *)commands->ct;
	compare_exec(cmd->exec, "cat -e");
}

void	test_4()
{
	test_setup("touch<<heredoc | ls -la | cat -e | <input >output");
	cmd = (t_command *)commands->ct;
	compare_exec(cmd->exec, "touch");
	compare_heredoc(&cmd->heredoc, "heredoc", e_d_in);
	commands++;
	cmd = (t_command *)commands->ct;
	compare_exec(cmd->exec, "ls -la");
	commands++;
	cmd = (t_command *)commands->ct;
	compare_exec(cmd->exec, "cat -e");
	commands++;
	cmd = (t_command *)commands->ct;
	compare_in(&cmd->in, "input", e_s_in);
	compare_out(&cmd->out, "output", e_s_out);
}

void	test_5()
{
	test_setup(" << \"heredoc mama \'mia\'\" <input /bin/cat >>append > output");
	cmd = (t_command *)commands->ct;
	compare_exec(cmd->exec, "/bin/cat");
	compare_in(&cmd->in, "input", e_s_in);
	compare_heredoc(&cmd->heredoc, "\"heredoc mama \'mia\'\"", e_d_in);
	compare_out(&cmd->out, "append", e_d_out);
	compare_out(&cmd->out, "output", e_s_out);
}

int	parser_test(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_1);
	RUN_TEST(test_2);
	RUN_TEST(test_3);
	RUN_TEST(test_4);
	RUN_TEST(test_5);
	return (UNITY_END());
}
