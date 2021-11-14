/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:35:34 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 18:15:25 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	*ft_alloc_b(int size)
{
	int	*st_b;
	int	i;

	i = 0;
	st_b = malloc(size * sizeof(int));
	if (!st_b)
		ft_raise_error();
	while (i < size + 1)
		*(st_b + i++) = -1;
	return (st_b);
}

void	ft_sort(int *st_a)
{
	int	*st_b;
	
	st_b = ft_alloc_b(ft_slen(st_a));
	ft_swap('b', st_b, st_a);
	print_stacks(st_a, st_b);
	printf("-> %d\n", ft_slen(st_a));
	printf("-> %d\n", ft_slen(st_b));
}