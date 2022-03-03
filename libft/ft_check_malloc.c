/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_malloc.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sde-quai <sde-quai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 10:04:50 by sde-quai      #+#    #+#                 */
/*   Updated: 2021/12/17 10:17:26 by sde-quai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_check_malloc(void *ptr)
{
	if (!ptr)
		exit(1);
}
