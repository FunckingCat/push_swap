/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:56:39 by unix              #+#    #+#             */
/*   Updated: 2021/11/25 16:24:29 by unix             ###   ########.fr       */
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

void	ft_move_chunk(int *st_a, int *st_b, int size, int lap)
{
	int	max;
	int	min;

	max = (ft_slen(st_a) + ft_slen(st_b)) / 2 + size * lap;
	min = (ft_slen(st_a) + ft_slen(st_b)) / 2 - size * lap;
	if (min <= 0)
		min = 1;
	if (max >= ft_slen(st_a) + ft_slen(st_b) - 1)
		max =(ft_slen(st_a) + ft_slen(st_b)) - 2;
	//print_stacks(st_a, st_b);
	//printf("MIN %d MAX %d SIZE %d LAP %d\n", min, max, size, lap);
	size *= 2;
	while (size-- > 0 && ft_slen(st_a) > 2)
	{
		while (ft_find_next(st_a, min, max) != ft_slen(st_a) - 1)
		{
			if (ft_find_next(st_a, min, max) >= ft_slen(st_a) / 2)
				ft_rotate('a', st_a, st_b);
			else
				ft_rev_rotate('a', st_a, st_b);
		}
		ft_push('b', st_a, st_b);
		if (st_b[ft_slen(st_a) -1] > st_b[ft_slen(st_a) -1])
			ft_swap('b', st_a, st_b);
	}
}

void	ft_move_back(int *st_a, int *st_b)
{
	int	current;
	int	next;
	int	i;
	
	while (ft_slen(st_b) != 0)
	{
		current = st_a[ft_slen(st_a) - 1] + 1;
		next = current + 2;
		i = 3;
		if (ft_slen(st_b) < 5)
		{
			ft_solve_top_three(st_a, st_b);
			i = 1;
			current = st_a[ft_slen(st_a) - 1] + 1;
			next = current;
		}
		while (i-- > 0)
		{
			while (ft_find_next(st_b, current, next) != ft_slen(st_b) - 1)
			{
				if (ft_find_next(st_b, current, next) >= ft_slen(st_b) / 2)
					ft_rotate('b', st_a, st_b);
				else
					ft_rev_rotate('b', st_a, st_b);
			}
			ft_push('a', st_a, st_b);
		}
		ft_solve_top_three(st_a, st_b);
	}
}

void	ft_solve_common(int *st_a, int *st_b)
{
	int chunk_size;
	int	i;

	chunk_size = ft_slen(st_a) * 0.15;
	i = 1;
	while (ft_slen(st_a) > 2)
	{
		ft_move_chunk(st_a, st_b, chunk_size, i++);
	}
	if (st_a[0] > st_a[1])
		ft_swap('a', st_a, st_b);
	ft_push('b', st_a, st_b);
	//print_stacks(st_a, st_b);
	//ft_solve_five(st_a, st_b);
	ft_move_back(st_a, st_b);
	//print_stacks(st_a, st_b);
}
