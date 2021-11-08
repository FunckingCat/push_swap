/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:55:59 by unix              #+#    #+#             */
/*   Updated: 2021/11/08 19:06:06 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_arr(int *arr, int len)
{
	int min;
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