/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:56:39 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 17:51:10 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_right(int *st_a, int *st_b)
{
	int	max;
	int	med;

	max = ft_slen(st_a) - 1;
	med = ft_slen(st_a) / 2 + 1;
	while (ft_slen(st_a) != 2)
	{
		if (ft_top(st_a, 1) == max || ft_top(st_a, 1) == 0)
			ft_rotate('a', st_a, st_b);
		else if (ft_top(st_a, 1) >= med)
			ft_push('b', st_a, st_b);
		else
		{
			ft_push('b', st_a, st_b);
			if (ft_slen(st_b) > 1)
				ft_rotate('b', st_a, st_b);
		}
	}
}

void	ft_roll(int val, int *st_a, int *st_b)
{
	while (ft_index(val, st_b) != ft_slen(st_b) - 1)
	{
		if ((ft_index(val, st_b) > ft_slen(st_b) / 2 - 1))
		{
			if (ft_top(st_a, 1) > val)
				ft_rotate('r', st_a, st_b);
			else
				ft_rotate('b', st_a, st_b);
		}
		else
		{
			if (ft_top(st_a, 1) < val && st_a[0] < val)
				ft_rev_rotate('r', st_a, st_b);
			else
				ft_rev_rotate('b', st_a, st_b);
		}
	}
}

void	ft_move_back(int *st_a, int *st_b)
{
	while (ft_slen(st_b) > 0)
	{
		ft_roll(st_b[ft_score(st_a, st_b)], st_a, st_b);
		while (ft_top(st_a, 1) < ft_top(st_b, 1) && st_a[0] < ft_top(st_b, 1))
			ft_rev_rotate('a', st_a, st_b);
		while (ft_top(st_a, 1) > ft_top(st_b, 1))
			ft_rotate('a', st_a, st_b);
		ft_push('a', st_a, st_b);
	}
}

void	ft_solve_common(int *st_a, int *st_b)
{
	ft_move_right(st_a, st_b);
	if (st_a[0] < st_a[1])
		ft_swap('a', st_a, st_b);
	ft_move_back(st_a, st_b);
	while (ft_top(st_a, 1) != ft_slen(st_a) - 1)
		ft_rev_rotate('a', st_a, st_a);
}
