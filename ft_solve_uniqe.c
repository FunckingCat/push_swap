/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_uniqe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:34:12 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 20:23:37 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_three(int *st)
{
	if (st[0] == 0 && st[1] == 2 && st[2] == 1)
		ft_swap('a', st, st);
	if (st[0] == 2 && st[1] == 1 && st[2] == 0)
	{
		ft_swap('a', st, st);
		ft_rev_rotate('a', st, st);
	}
	if (st[0] == 1 && st[1] == 2 && st[2] == 0)
		ft_rotate('a', st, st);
	if (st[0] == 1 && st[1] == 0 && st[2] == 2)
	{
		ft_swap('a', st, st);
		ft_rotate('a', st, st);
	}
	if (st[0] == 2 && st[1] == 0 && st[2] == 1)
		ft_rev_rotate('a', st, st);
}

void	ft_solve_four(int *st_a, int *st_b)
{
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