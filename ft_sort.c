/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:35:34 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 14:20:08 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_three(int *st)
{
	if (ft_top(st, 3) < ft_top(st, 1) && ft_top(st, 1) < ft_top(st, 2))
		ft_swap('a', st, st);
	if (ft_top(st, 1) < ft_top(st, 2) && ft_top(st, 2) < ft_top(st, 3))
	{
		ft_swap('a', st, st);
		ft_rev_rotate('a', st, st);
	}
	if (ft_top(st, 1) < ft_top(st, 3) && ft_top(st, 3) < ft_top(st, 2))
		ft_rotate('a', st, st);
	if (ft_top(st, 2) < ft_top(st, 3) && ft_top(st, 3) < ft_top(st, 1))
	{
		ft_swap('a', st, st);
		ft_rotate('a', st, st);
	}
	if (ft_top(st, 2) < ft_top(st, 1) && ft_top(st, 1) < ft_top(st, 3))
		ft_rev_rotate('a', st, st);
}

void	ft_solve_four(int *st_a, int *st_b)
{
	if (ft_is_sorted(st_a, 0))
		return ;
	if (ft_index(3, st_a) < 2)
	{
		while (st_a[3] != 3)
			ft_rev_rotate('a', st_a, st_b);
	}
	while (st_a[3] != 3)
		ft_rotate('a', st_a, st_b);
	ft_push('b', st_a, st_b);
	ft_solve_three(st_a);
	ft_push('a', st_a, st_b);
}

void	ft_solve_five(int *st_a, int *st_b)
{
	if (ft_is_sorted(st_a, 0))
		return ;
	if (ft_index(4, st_a) < 2)
	{
		while (st_a[4] != 4)
			ft_rev_rotate('a', st_a, st_b);
	}
	while (st_a[4] != 4)
		ft_rotate('a', st_a, st_b);
	ft_push('b', st_a, st_b);
	ft_solve_four(st_a, st_b);
	ft_push('a', st_a, st_b);
}

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
}
