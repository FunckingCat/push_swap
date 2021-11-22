/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:55:59 by unix              #+#    #+#             */
/*   Updated: 2021/11/22 18:38:19 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_raise_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_min_arr(int *arr, int len)
{
	int	min;
	int	index;

	min = INT_MAX;
	index = len;
	while (len--)
	{
		if (arr[len] < min)
		{
			min = arr[len];
			index = len;
		}
	}
	return (index);
}

int	ft_max_arr(int *arr, int len)
{
	int	max;
	int	index;

	max = INT_MIN;
	index = len;
	while (len--)
	{
		if (arr[len] > max)
		{
			max = arr[len];
			index = len;
		}
	}
	return (index);
}

int	ft_is_sorted(int *arr, int direction)
{
	while (*(arr + 1) != -1)
	{
		if (direction == 0)
		{
			if (*arr > *(arr + 1))
				return (0);
		}
		else
		{
			if (*arr < *(arr + 1))
				return (0);
		}
		arr++;
	}
	return (1);
}

int	ft_in(int elem, int min, int max)
{
	if (elem >= min && elem <= max)
		return (1);
	return (0);
}
