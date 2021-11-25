/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_midleware.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:43:37 by unix              #+#    #+#             */
/*   Updated: 2021/11/25 11:22:12 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_case_one(int *st_a, int *st_b)
{
	ft_push('b', st_a, st_b);
	ft_swap('a', st_a, st_b);
	ft_push('a', st_a, st_b);
	ft_swap('a', st_a, st_b);
}

void	ft_case_two(int *st_a, int *st_b)
{
	ft_push('b', st_a, st_b);
	ft_swap('a', st_a, st_b);
	ft_push('a', st_a, st_b);
}