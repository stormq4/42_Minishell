/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_specials.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:56:45 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/09/16 18:57:09 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

int	find_len_until_special_char(char *var)
{
	int	i;

	i = 0;
	while (var[i] && !check_special_expand(var[i]))
		i++;
	return (i);
}

t_list	*special_expand_order(char *var)
{
	t_list	*order;
	t_list	*new;
	char	*tmp;
	int		i;

	order = NULL;
	i = 0;
	while (var[i])
	{
		if (check_special_expand(var[i]))
		{
			tmp = malloc(sizeof(char) * 2);
			tmp[0] = var[i];
			tmp[1] = 0;
		}
		else
		{
			tmp = ft_substr(var + i, 0, find_len_until_special_char(var + i));
			i += find_len_until_special_char(var + i) - 1;
		}
		new = ft_lstnew(tmp);
		ft_lstadd_back(&order, new);
		i++;
	}
	return (order);
}

int	env_in_special(char *str, char **envp)
{
	t_list	*order;
	t_list	*start;

	order = special_expand_order(str);
	start = order;
	while (order != NULL)
	{
		if (env_in_str((char *)order->ct, envp))
		{
			free_order_lst(start);
			return (1);
		}
		order = order->next;
	}
	free_order_lst(start);
	return (0);
}

t_bool	has_special_expand_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_special_expand(str[i]))
			return (true);
		i++;
	}
	return (false);
}

char	*replace_special_var(char *str, char **envp)
{
	t_list	*order;
	t_list	*start;
	char	*tmp;

	order = special_expand_order(str);
	start = order;
	while (order != NULL)
	{
		if (env_in_str((char *)order->ct, envp))
		{
			tmp = order->ct;
			order->ct = replace_env_var(order->ct, envp);
			free(tmp);
		}
		order = order->next;
	}
	tmp = order_lst_join(&start);
	free_order_lst(start);
	free(order);
	return (tmp);
}
