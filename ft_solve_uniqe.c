/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_uniqe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:34:12 by unix              #+#    #+#             */
/*   Updated: 2021/11/25 10:09:22 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_three(int *st)
{
	int a[3];

	a[0] = st[ft_slen(st) - 3];
	a[1] = st[ft_slen(st) - 2];
	a[2] = st[ft_slen(st) - 1];
	if (ft_is_sorted(st, 0))
		return ;
	if (a[0] < a[2] && a[2] < a[1])
		ft_swap('a', st, st);
	if (a[2] < a[1] && a[1] < a[0])
	{
		ft_swap('a', st, st);
		ft_rev_rotate('a', st, st);
	}
	if (a[2] < a[0] && a[0] < a[1])
		ft_rotate('a', st, st);
	if (a[1] < a[0] && a[0] < a[2])
	{
		ft_swap('a', st, st);
		ft_rotate('a', st, st);
	}
	if (a[1] < a[2] && a[2] < a[0])
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
