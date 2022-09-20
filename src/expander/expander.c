/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:41:46 by gpirro            #+#    #+#             */
/*   Updated: 2022/09/16 18:53:10 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>
#include <libft.h>

/**
 * @brief replaces the env variables in exec
 * 
 * @param exec 
 */
void	expand_exec(t_exec *exec, char **envp)
{
	if (exec->cmd)
		replace(&(exec->cmd), envp);
}

void	expand_input(t_list	**in, char **envp)
{
	t_list	*input;
	t_red	*red;

	input = *in;
	if (!input)
		return ;
	while (input)
	{
		red = (t_red *)input->ct;
		if (red->type == e_s_in)
			if (red->file)
				replace(&red->file, envp);
		input = input->next;
	}
}

void	expand_output(t_list **out, char **envp)
{
	t_list	*output;
	t_red	*red;

	output = *out;
	if (!output)
		return ;
	while (output)
	{
		red = (t_red *)output->ct;
		if (red->type == e_s_out)
			if (red->file)
				replace(&red->file, envp);
		output = output->next;
	}
}

void	replace(char **line, char **envp)
{
	char	*tmp;
	t_list	*split;

	split = NULL;
	tmp = *line;
	while (**line)
	{
		if (**line == ' ')
		{
			add_space(&split);
			(*line)++;
		}
		else if (split_item(line, &split))
		{
			*line = tmp;
			return ;
		}
	}
	replace_env_var_in_lst(&split, envp);
	replace_g_error_in_lst(&split);
	*line = lst_join(&split);
	free_split(&split);
	free(tmp);
}

void	expander(t_list **cmd_list, char **envp)
{
	t_list		*cmds;
	t_command	*cmd;
	t_exec		*exec;

	cmds = (*cmd_list);
	while (cmds)
	{
		cmd = (t_command *)cmds->ct;
		exec = (t_exec *)cmd->exec;
		expand_exec(exec, envp);
		expand_input(&(cmd->in), envp);
		expand_output(&(cmd->out), envp);
		cmds = cmds->next;
	}
}
