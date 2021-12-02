/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:37 by unix              #+#    #+#             */
/*   Updated: 2021/12/02 16:43:57 by tyamcha          ###   ########.fr       */
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
		return (NULL);
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
			ft_raise_error(NULL, NULL);
		st_b = ft_alloc_b(ft_slen(st_a));
		if (!st_b)
			ft_raise_error(st_a, NULL);
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
		ft_putstr_fd("Error - too few args, usage: ./push_swap [...list...]", 1);
	return (0);
}
