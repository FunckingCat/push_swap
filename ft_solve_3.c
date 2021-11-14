/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:34:12 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 19:51:17 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_three(int *st)
{
	if (st[0] == 0 && st[1] == 2 && st[2] == 1)
		ft_swap('a', st, st);
	if (st[0] == 2 && st[1] == 1 && st[2] == 0)
	{
		ft_swap('a', st, st);
		ft_rev_rotate('a', st, st);
	}
	if (st[0] == 1 && st[1] == 2 && st[2] == 0)
		ft_rotate('a', st, st);
	if (st[0] == 1 && st[1] == 0 && st[2] == 2)
	{
		ft_swap('a', st, st);
		ft_rotate('a', st, st);
	}
	if (st[0] == 2 && st[1] == 0 && st[2] == 1)
		ft_rev_rotate('a', st, st);
}