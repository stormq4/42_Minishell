/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_min.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: stormdequay <stormdequay@student.codam.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/12 11:47:00 by stormdequay   #+#    #+#                 */
/*   Updated: 2022/03/23 11:11:49 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief Finds minimum size_t in nr array and returns it
 * 
 * @param nr_arr pointer size_t array
 * @param len nr of size_t's in array
 * @return size_t 
 */
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
