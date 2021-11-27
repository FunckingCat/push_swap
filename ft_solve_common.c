/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:56:39 by unix              #+#    #+#             */
/*   Updated: 2021/11/27 20:47:22 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_next(int *stack, int min, int max)
{
	int	pos_top;
	int	pos_bot;
	int	count;

	count = 0;
	pos_top = -1;
	pos_bot = -1;
	while (pos_top == -1)
	{
		if (ft_in(stack[count], min, max))
			pos_top = count;
		count++;
	}
	count = ft_slen(stack) - 1;
	while (pos_bot == -1)
	{
		if (ft_in(stack[count], min, max))
			pos_bot = count;
		count--;
	}
	if (pos_top < ft_slen(stack) - pos_bot - 1)
		return (pos_top);
	else
		return (pos_bot);
}

void	ft_move_chunk(int *st_a, int *st_b, int size, int lap, int med)
{
	int	max;
	int	min;

	max = ft_slen(st_a) - 1;
	while (ft_slen(st_a) != 2)
	{
		if (ft_top(st_a, 1) == max || ft_top(st_a, 1) == 0)
			ft_rotate('a', st_a, st_b);
		else if (ft_top(st_a, 1) <= med)
			ft_push('b', st_a, st_b);
		else
		{
			ft_push('b', st_a, st_b);
			if (ft_slen(st_b) > 1)
				ft_rotate('b', st_a, st_b);
		}
	}
}

void	ft_move_back(int *st_a, int *st_b, int med)
{
	int	count;
	int	ind;

	count = 0;
	while (ft_slen(st_b) > 0)
	{
		ft_roll(ft_score(st_a, st_b), st_b);
		while (ft_top(st_a, 1) < ft_top(st_b, 1) && st_a[0] < ft_top(st_b, 1))
		{
			ft_rev_rotate('a', st_a, st_b);
			count--;
		}
		while (ft_top(st_a, 1) > ft_top(st_b, 1))
		{
			ft_rotate('a', st_a, st_b);
			count++;
		}
		ft_push('a', st_a, st_b);
	}
}

void	ft_solve_common(int *st_a, int *st_b)
{
	int chunk_size;
	int	med;
	int	i;

	med = ft_slen(st_a) / 2 + 1;
	chunk_size = ft_slen(st_a) * 0.15;
	i = 1;
	while (ft_slen(st_a) > 2)
	{
		ft_move_chunk(st_a, st_b, chunk_size, i++, med);
	}
	if (st_a[0] < st_a[1])
		ft_swap('a', st_a, st_b);
	//print_stacks(st_a, st_b);
	ft_move_back(st_a, st_b, med);
	while (ft_top(st_a, 1) != ft_slen(st_a) - 1)
		ft_rev_rotate('a', st_a, st_a);
	//print_stacks(st_a, st_b);
}
