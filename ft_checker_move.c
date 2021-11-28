/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:07:36 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 18:45:47 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char mode, int *st_a, int *st_b)
{
	if (mode == 'a' && ft_slen(st_a) > 1)
	{
		ft_swap_val(st_a + ft_slen(st_a) - 1, st_a + ft_slen(st_a) - 2);
	}
	else if (mode == 'b' && ft_slen(st_b) > 1)
	{
		ft_swap_val(st_b + ft_slen(st_b) - 1, st_b + ft_slen(st_b) - 2);
	}
	else if (mode == 's')
	{
		if (ft_slen(st_a) > 1)
			ft_swap_val(st_a + ft_slen(st_a) - 1, st_a + ft_slen(st_a) - 2);
		if (ft_slen(st_b) > 1)
			ft_swap_val(st_b + ft_slen(st_b) - 1, st_b + ft_slen(st_b) - 2);
	}
	else
		ft_raise_error(st_a, st_b);
}

void	ft_push(char mode, int *st_a, int *st_b)
{
	if (mode == 'a' && ft_slen(st_b) > 0)
	{
		ft_swap_val(st_b + ft_slen(st_b) - 1, st_a + ft_slen(st_a));
	}
	else if (mode == 'b' && ft_slen(st_a) > 0)
	{
		ft_swap_val(st_a + ft_slen(st_a) - 1, st_b + ft_slen(st_b));
	}
	else
		ft_raise_error(st_a, st_b);
}

void	ft_rot(int *stack, int direction)
{
	int	len;
	int	i;

	len = ft_slen(stack);
	if (direction == 0)
	{
		i = len - 1;
		while (i > 0)
		{
			ft_swap_val(&stack[i], &stack[i - 1]);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len - 1)
		{
			ft_swap_val(&stack[i], &stack[i + 1]);
			i++;
		}
	}
}

void	ft_rotate(char mode, int *st_a, int *st_b)
{
	if (mode == 'a' && ft_slen(st_a) > 1)
	{
		ft_rot(st_a, 0);
	}
	else if (mode == 'b' && ft_slen(st_b) > 1)
	{
		ft_rot(st_b, 0);
	}
	else if (mode == 'r')
	{
		if (ft_slen(st_a) > 1)
			ft_rot(st_a, 0);
		if (ft_slen(st_b) > 1)
			ft_rot(st_b, 0);
	}
	else
		ft_raise_error(st_a, st_b);
}

void	ft_rev_rotate(char mode, int *st_a, int *st_b)
{
	if (mode == 'a' && ft_slen(st_a) > 1)
	{
		ft_rot(st_a, 1);
	}
	else if (mode == 'b' && ft_slen(st_b) > 1)
	{
		ft_rot(st_b, 1);
	}
	else if (mode == 'r')
	{
		if (ft_slen(st_a) > 1)
			ft_rot(st_a, 1);
		if (ft_slen(st_b) > 1)
			ft_rot(st_b, 1);
	}
	else
		ft_raise_error(st_a, st_b);
}
