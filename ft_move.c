/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:07:36 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 17:48:02 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char mode, int *st_a, int *st_b)
{
	if (mode == 'a' && ft_slen(st_a) > 1)
	{
		ft_swap_val(st_a[ft_slen(st_a) - 1], st_a[ft_slen(st_a) - 2]);
		ft_putstr_fd("sa\n", 1);
	}
	else if (mode == 'b' && ft_slen(st_b) > 1)
	{
		ft_swap_val(st_a[ft_slen(st_b) - 1], st_a[ft_slen(st_b) - 2]);
		ft_putstr_fd("sb\n", 1);
	}
	else
	{
		ft_swap_val(st_a[ft_slen(st_a) - 1], st_a[ft_slen(st_a) - 2]);
		ft_swap_val(st_a[ft_slen(st_b) - 1], st_a[ft_slen(st_b) - 2]);
		ft_putstr_fd("ss\n", 1);
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