/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:07:36 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 17:37:15 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char mode, int *st_a, int *st_b)
{
	if (mode == 'a' && ft_slen(st_a) > 1)
		ft_swap_val(st_a[ft_slen(st_a) - 1], st_a[ft_slen(st_a) - 2]);
	else if (mode == 'b' && ft_slen(st_b) > 1)
		ft_swap_val(st_a[ft_slen(st_b) - 1], st_a[ft_slen(st_b) - 2]);
	else
	{
		ft_swap('a', st_a, st_b);
		ft_swap('b', st_a, st_b);
	}
}

// void	ft_push(char mode, int *st_a, int *st_b)
// {
	
// }

// void	ft_rotate(char mode, int *st_a, int *st_b)
// {
	
// }

// void	ft_rev_rotate(char mode, int *st_a, int *st_b)
// {
	
// }