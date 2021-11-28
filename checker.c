/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:32:40 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 14:59:53 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_handle_action(char *action, int *st_a, int *st_b)
{
	if (ft_strlen(action) == 3)
	{
		if (action[0] == 's')
			ft_swap(action[1], st_a, st_b);
		else if (action[0] == 'p')
			ft_push(action[1], st_a, st_b);
		else if (action[0] == 'r')
			ft_rotate(action[1], st_a, st_b);
		else
			ft_raise_error();
	}
	else if (ft_strlen(action) == 4)
	{
		if (action[0] == 'r' && action[1] == 'r')
			ft_rev_rotate(action[2], st_a, st_b);
		else
			ft_raise_error();
	}
	else
		ft_raise_error();
}

void	ft_listen_action(int *stack)
{
	char	*action;
	int		*stack_b;

	stack_b = ft_alloc_b(ft_slen(stack));
	print_stacks(stack, stack_b);
	action = get_next_line(0);
	while (action && ft_strlen(action) > 1)
	{
		ft_handle_action(action, stack, stack_b);
		print_stacks(stack, stack_b);
		action = get_next_line(0);
	}
	free(stack_b);
	if (ft_is_sorted(stack, 0))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	int	*stack;

	if (argc != 1)
	{
		stack = ft_parse_stack(argv + 1, argc - 1);
		if (!stack)
			ft_raise_error();
		ft_listen_action(stack);
		free(stack);
	}
	return (0);
}
