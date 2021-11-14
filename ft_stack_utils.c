/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:13:05 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 17:31:51 by unix             ###   ########.fr       */
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