/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:37 by unix              #+#    #+#             */
/*   Updated: 2021/11/22 15:12:20 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*stack;

	if (argc != 1)
	{
		stack = ft_parse_stack(argv + 1, argc - 1);
		if (!stack)
			ft_raise_error();
		ft_sort(stack);
		free(stack);
	}
	else
		ft_raise_error();
	return (0);
}
