/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:56:39 by unix              #+#    #+#             */
/*   Updated: 2021/11/22 16:15:19 by unix             ###   ########.fr       */
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

void	ft_move_chunk(int *st_a, int *st_b, int size)
{
	int	max;
	int	min;

	max = st_a[ft_max_arr(st_a, ft_slen(st_a))];
	min = max - size + 1;
	//printf("MOVE CHUNK - (max - %d) (min - %d) (size - %d)\n", max, min, size);
	while (size-- > 0)
	{
		//printf("-> %d\n", ft_find_next(st_a, min, max));
		while (ft_find_next(st_a, min, max) != ft_slen(st_a) - 1)
		{
			if (ft_find_next(st_a, min, max) >= ft_slen(st_a) / 2)
				ft_rotate('a', st_a, st_b);
			else
				ft_rev_rotate('a', st_a, st_b);
		}
		ft_push('b', st_a, st_b);
		//print_stacks(st_a, st_b);
	}
}

void	ft_move_back(int *st_a, int *st_b)
{
	int	current;

	while (ft_slen(st_b) != 0)
	{
		current = st_a[ft_slen(st_a) - 1] + 1;
		//printf("-> %d\n", ft_find_next(st_b, current, current));
		while (ft_find_next(st_b, current, current) != ft_slen(st_b) - 1)
		{
			if (ft_find_next(st_b, current, current) >= ft_slen(st_b) / 2)
				ft_rotate('b', st_a, st_b);
			else
				ft_rev_rotate('b', st_a, st_b);
		}
		ft_push('a', st_a, st_b);
		//print_stacks(st_a, st_b);
	}
}

void	ft_solve_common(int *st_a, int *st_b)
{
	while (ft_slen(st_a) > 5)
	{
		if (ft_slen(st_a) - ft_slen(st_a) / 2 < 5)
			ft_move_chunk(st_a, st_b, ft_slen(st_a) - 5);
		else
			ft_move_chunk(st_a, st_b, ft_slen(st_a) / 2);
	}
	ft_solve_five(st_a, st_b);
	//print_stacks(st_a, st_b);
	ft_move_back(st_a, st_b);
}
