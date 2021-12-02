/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:32:40 by unix              #+#    #+#             */
/*   Updated: 2021/12/02 10:54:18 by tyamcha          ###   ########.fr       */
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
		return (NULL);
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
			ft_raise_error(st_a, st_b);
	}
	else if (ft_strlen(action) == 4)
	{
		if (action[0] == 'r' && action[1] == 'r')
			ft_rev_rotate(action[2], st_a, st_b);
		else
			ft_raise_error(st_a, st_b);
	}
	else
		ft_raise_error(st_a, st_b);
}

void	ft_listen_action(int *st_a, int *st_b)
{
	char	*action;

	action = get_next_line(0);
	while (action)
	{
		ft_handle_action(action, st_a, st_b);
		action = get_next_line(0);
	}
	if (ft_is_sorted(st_a, 0) && ft_slen(st_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	int		*st_a;
	int		*st_b;

	if (argc != 1)
	{
		st_a = ft_parse_stack(argv + 1, argc - 1);
		if (!st_a)
			ft_raise_error(NULL, NULL);
		st_b = ft_alloc_b(ft_slen(st_a));
		if (!st_b)
			ft_raise_error(st_a, NULL);
		ft_listen_action(st_a, st_b);
		free(st_a);
		free(st_b);
	}
	return (0);
}
