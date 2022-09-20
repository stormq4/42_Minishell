/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   append_redirect.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 16:14:05 by sde-quai      #+#    #+#                 */
/*   Updated: 2022/09/15 14:25:38 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @brief checks if next token after a redirect is valid (only a word)
 * 
 * @param next_token 
 */
static t_bool	check_redirect_pair(t_token *next_token)
{
	char	*error_str;

	if (next_token->type != e_word)
	{
		error_str = ft_strjoin("minishell: syntax error near \
unexpected token `", next_token->token_data);
		ft_check_malloc(error_str);
		g_error = 258;
		ft_putendl_fd(error_str, 2);
		free(error_str);
		return (false);
	}
	return (true);
}

/**
 * @brief appends or creates the new file name.
 * 
 * @param red t_red
 * @param token_lst t_list
 * @param token t_token
 * @param append_lst t_list
 */
static t_bool	check_first_append(t_red *red, t_list **token_lst, \
t_token *token, t_list *append_lst)
{
	t_list	*new;
	t_token	*next_token;

	next_token = (t_token *)(*token_lst)->ct;
	if (!check_redirect_pair(next_token))
		return (false);
	if (!red->file)
	{
		red->file = ft_strdup(next_token->token_data);
		red->type = token->type;
	}
	else if (red->file)
	{
		red = malloc(sizeof(t_red));
		ft_check_malloc(red);
		red->file = ft_strdup(next_token->token_data);
		red->type = token->type;
		new = ft_lstnew(red);
		ft_lstadd_back(&append_lst, new);
	}
	return (true);
}

/**
 * @brief the tokens are appended to the corrosponded input or output
 * list.
 * 
 * @param token_lst t_list
 * @param append t_list
 * @param token t_token
 */
static t_bool	append_redirect_token(t_list **token_lst, t_list **append, \
t_token *token)
{
	t_red	*red;
	t_list	*append_lst;
	t_list	*b_append;

	b_append = *append;
	append_lst = ft_lstlast(b_append);
	red = (t_red *)append_lst->ct;
	if ((*token_lst)->next)
	{
		*token_lst = (*token_lst)->next;
		if (!check_first_append(red, token_lst, token, append_lst))
			return (false);
		if (*token_lst)
			*token_lst = (*token_lst)->next;
	}
	else
	{
		(*token_lst) = (*token_lst)->next;
		g_error = 258;
		ft_putstr_fd("minishell: syntax error near unexpectd token \
`newline'\n", 2);
		return (false);
	}
	return (true);
}

/**
 * @brief check to check if the token needs be added to the input or output
 * given its token type.
 * 
 * @param token_lst t_list
 * @param command t_command
 * @param token t_token
 */
t_bool	append_redirect(t_list **token_lst, t_command *command, \
t_token *token)
{
	if (token->type == e_s_in || token->type == e_d_in)
	{
		if (!append_redirect_token(token_lst, &command->in, token))
			return (false);
	}
	else if (token->type == e_s_out || token->type == e_d_out)
	{
		if (!append_redirect_token(token_lst, &command->out, token))
			return (false);
	}
	return (true);
}
