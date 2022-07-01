/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/15 17:46:58 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/06/21 14:50:03 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	split_normal(char **line, t_list **split)
{
	int			i;
	char		*str;
	t_expand	*item;
	t_list		*new;

	i = 0;
	while (!is_split_c((*line)[i]))
		i++;
	str = pmalloc(sizeof(char) * (i + 1));
	ft_strlcpy(str, *line, (i + 1));
	item = pmalloc(sizeof(t_expand));
	item->split = str;
	item->expand = 1;
	new = ft_lstnew(item);
	ft_check_malloc(new);
	ft_lstadd_back(split, new);
	*line = *line + i;
	return (0);
}

int	split_singleq(char **line, t_list **split)
{
	int			i;
	char		*str;
	t_expand	*item;
	t_list		*new;

	i = 0;
	while ((*line)[++i] != '\'')
	{
		if ((*line)[i] == '\0')
		{
			free_split(split);
			return (1);
		}
	}
	i++;
	str = pmalloc(sizeof(char) * (i - 1));
	ft_strlcpy(str, (*line + 1), (i - 1));
	item = pmalloc(sizeof(t_expand));
	item->split = str;
	item->expand = 0;
	new = ft_lstnew(item);
	ft_check_malloc(new);
	ft_lstadd_back(split, new);
	*line = *line + i;
	return (0);
}

int	split_doubleq(char **line, t_list **split)
{
	int			i;
	char		*str;
	t_expand	*item;
	t_list		*new;

	i = 0;
	while ((*line)[++i] != '\"')
	{
		if ((*line)[i] == '\0')
		{
			free_split(split);
			return (1);
		}
	}
	i++;
	str = pmalloc(sizeof(char) * (i - 1));
	ft_strlcpy(str, (*line + 1), (i - 1));
	item = pmalloc(sizeof(t_expand));
	item->split = str;
	item->expand = 1;
	new = ft_lstnew(item);
	ft_check_malloc(new);
	ft_lstadd_back(split, new);
	*line = *line + i;
	return (0);
}

int	split_item(char **line, t_list **split)
{
	if (**line == '\"')
		return (split_doubleq(line, split));
	if (**line == '\'')
		return (split_singleq(line, split));
	return (split_normal(line, split));
}

int	add_space(t_list **split)
{
	char		*str;
	t_expand	*item;
	t_list		*new;

	str = pmalloc(sizeof(char) * 2);
	str[0] = ' ';
	str[1] = '\0';
	item = pmalloc(sizeof(t_expand));
	item->split = str;
	item->expand = 1;
	new = ft_lstnew(item);
	ft_check_malloc(new);
	ft_lstadd_back(split, new);
	return (0);
}
