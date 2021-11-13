/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:37 by unix              #+#    #+#             */
/*   Updated: 2021/11/13 20:31:56 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_indexate(int *arr, int len)
{
	int	*res;
	int	id;
	int	i;

	id = 0;
	i = 0;
	res = malloc((len + 1) * sizeof(int));
	res[ft_max_arr(arr, len)] = len - 1;
	while (i < len - 1)
	{
		res[ft_min_arr(arr, len)] = id++;
		arr[ft_min_arr(arr, len)] = INT_MAX;
		i++;
	}
	res[len] = -1;
	free(arr);
	return (res);
}

int	*ft_parse_stack(char **st)
{
	int	*res;
	int	len;
	int	i;

	len = 0;
	while (st[len])
		len++;
	res = malloc((len) * sizeof(int));
	i = 0;
	while (st[i])
	{
		res[len - i++ - 1] = ft_atoi(st[i]);
	}
	if (ft_has_dups(res, len))
	{
		free(res);
		return (NULL);
	}
	res = ft_indexate(res, len);
	return (res);
}

void	free_char_arr(char **st)
{
	while (*st)
	{
		free(*st);
		st++;
	}
}

int	main(int argc, char **argv)
{
	char	**st;
	int		*stack;

	if (argc == 2)
	{
		st = ft_split(argv[1], ' ');
		if (ft_validate_stack(st))
		{
			stack = ft_parse_stack(st);
			if (stack)
			{
				for (int i = 0; stack[i] != -1; i++)
				{
					printf("%d\n", stack[i]);
				}
				printf("->  %d\n", ft_is_sorted(stack, 1));
				free(stack);
			}
			else
				ft_putstr_fd("Error(stack parse)\n", 1);
		}
		else
			ft_putstr_fd("Error(stack validate)\n", 1);
		free_char_arr(st);
		free(st);
		return (0);
	}
	else
		ft_putstr_fd("Error(args)\n", 1);
	return (0);
}

// ss()
// {
//     make && echo "---------------------------------" && ./push_swap $1
// }

// aa()
// {
//     make && echo "---------------------------------" && ./push_swap "16 23 98 0 13 54 83 46 111 145 73 6"
// }

// as()
// {
//     make && echo "---------------------------------" && ./push_swap "2 3 1"
// }

// ad()
// {
//     make && echo "---------------------------------" && ./push_swap "3 2 1 5 4"
// }