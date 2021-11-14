/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:13:05 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 20:23:20 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_slen(int *stack)
{
	int	len;

	len = 0;
	while (*stack++ != -1)
		len++;
	return (len);
}

void	ft_swap_val(int *d1, int *d2)
{
	int	tmp;

	if (d1 && d2)
	{
		tmp = *d1;
		*d1 = *d2;
		*d2 = tmp;
	}
}

int	ft_index(int val, int *stack)
{
	int	i;

	i = 0;
	while (i < ft_slen(stack))
	{
		if (stack[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

void	print_stacks(int *st_a, int *st_b)
{
	int	i;

	i = ft_slen(st_a);
	if (ft_slen(st_b) > i)
		i = ft_slen(st_b);
	while (i >= 0)
	{
		printf("%6d   %6d\n", st_a[i], st_b[i]);
		i--;
	}
}