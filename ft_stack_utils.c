/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:13:05 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 14:29:20 by unix             ###   ########.fr       */
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

int	ft_top(int	*st, int pos)
{
	return (st[ft_slen(st) - pos]);
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
