/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:35:34 by unix              #+#    #+#             */
/*   Updated: 2021/11/22 18:29:36 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_alloc_b(int size)
{
	int	*st_b;
	int	i;

	i = 0;
	st_b = malloc((size + 1) * sizeof(int));
	if (!st_b)
		ft_raise_error();
	while (i < size + 1)
		*(st_b + i++) = -1;
	return (st_b);
}

void	ft_sort(int *st_a)
{
	int	*st_b;

	if (ft_is_sorted(st_a, 0))
		return ;
	st_b = ft_alloc_b(ft_slen(st_a));
	//print_stacks(st_a, st_b);
	if (ft_slen(st_a) == 2)
		ft_rotate('a', st_a, st_b);
	if (ft_slen(st_a) == 3)
		ft_solve_three(st_a);
	if (ft_slen(st_a) == 4)
		ft_solve_four(st_a, st_b);
	if (ft_slen(st_a) == 5)
		ft_solve_five(st_a, st_b);
	if (ft_slen(st_a) > 5)
		ft_solve_common(st_a, st_b);
	//print_stacks(st_a, st_b);
}
