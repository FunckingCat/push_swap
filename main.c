/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:37 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 14:56:09 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_alloc_b(int size)
{
	int	*st_b;
	int	i;

	i = 0;
	st_b = malloc((size + 1) * sizeof(int));
	if (!st_b)
		ft_raise_error();
	while (i < size + 1)
		*(st_b + i++) = -1;
	return (st_b);
}

int	main(int argc, char **argv)
{
	int	*st_a;
	int	*st_b;

	if (argc != 1)
	{
		st_a = ft_parse_stack(argv + 1, argc - 1);
		if (!st_a)
			ft_raise_error();
		st_b = ft_alloc_b(ft_slen(st_a));
		if (!st_b)
			ft_raise_error();
		if (!ft_is_sorted(st_a, 0))
		{
			if (ft_slen(st_a) > 5)
				ft_solve_common(st_a, st_b);
			else	
				ft_solve_small(st_a, st_b);
		}
		free(st_a);
		free(st_b);
	}
	else
		ft_raise_error();
	return (0);
}

void	print_stacks(int *st_a, int *st_b)
{
	int	i;

	i = ft_slen(st_a);
	if (ft_slen(st_b) > i)
		i = ft_slen(st_b);
	while (i >= 0)
	{
		printf("%6d   %6d\n", st_a[i], st_b[i]);
		i--;
	}
	printf("---------------------\n");
}