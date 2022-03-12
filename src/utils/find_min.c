/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_min_size_t.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 11:47:00 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/12 11:53:12 by stormdequay   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	find_min_size_t(size_t *nr_arr, size_t len)
{
	size_t	i;
	size_t	min;

	i = 0;
	min = nr_arr[0];
	while (1)
	{
		if (i == len)
			break ;
		else if (nr_arr[i] < min)
			min = nr_arr[i];
		i++;
	}
	return (min);
}
