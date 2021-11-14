/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:35:34 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 17:46:14 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int *st_a)
{
	int	*st_b;
	int	i;

	i = 0;
	st_b = malloc(ft_slen(st_a) * sizeof(int));
	while (i < ft_slen(st_a) + 1)
		*(st_b + i++) = -1;
	for (int i = 0; st_a[i] != -1; i++)
	{
		printf("%d\n", st_a[i]);
	}
	printf("-> %d\n", ft_slen(st_a));
	printf("-> %d\n", ft_slen(st_b));
}