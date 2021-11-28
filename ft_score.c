/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:24:12 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 15:00:10 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_second_part(int val, int *st)
{
	int	count;
	int	i;

	count = 0;
	if (st[ft_slen(st) - 1] < val)
	{
		count = 0;
		while (st[count] < val)
			count++;
	}
	else
	{
		i = ft_slen(st) - 1;
		while (st[i--] > val)
			count++;
	}
	return (count);
}

int	ft_first_part(int val, int *st)
{
	if (ft_index(val, st) > ft_slen(st) / 2 - 1)
		return (ft_slen(st) - ft_index(val, st) - 1);
	else
		return (ft_index(val, st) + 1);
	return (0);
}

int	ft_score(int *st_a, int *st_b)
{
	int	min_score;
	int	score;
	int	index;
	int	i;

	i = 0;
	min_score = INT_MAX;
	while (i < ft_slen(st_b))
	{
		score = ft_first_part(st_b[i], st_b) + ft_second_part(st_b[i], st_a);
		if (score <= min_score)
		{
			min_score = score;
			index = i;
		}
		i++;
	}
	return (index);
}
