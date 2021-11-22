/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:40:30 by unix              #+#    #+#             */
/*   Updated: 2021/11/22 15:25:06 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
		i++;
	}
	if (i > 10)
		return (0);
	return (1);
}

int	ft_has_dups(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_indexate(int *arr, int len)
{
	int	*res;
	int	id;
	int	i;

	id = 0;
	i = 0;
	res = malloc((len + 1) * sizeof(int));
	if (!res)
		ft_raise_error();
	res[ft_min_arr(arr, len)] = len - 1;
	while (i < len - 1)
	{
		res[ft_max_arr(arr, len)] = id++;
		arr[ft_max_arr(arr, len)] = INT_MIN;
		i++;
	}
	res[len] = -1;
	free(arr);
	return (res);
}

int		*ft_parse_stack(char **st, int len)
{
	int	*res;
	int	i;

	i = len - 1;
	res = malloc(len * sizeof(int));
	if (!res)
		ft_raise_error();
	while (i > 0)
	{
		if (!ft_str_is_digit(st[i]))
			return (NULL);
		else if (st[i][0] == '0' && st[i][1] == '\0')
			res[i] = 0;
		else if (st[i][0] == '-' && st[i][1] == '1' && st[i][2] == '\0')
			res[i] = -1;
		else if (ft_atoi(st[i]) == -1 || ft_atoi(st[i]) == 0)
			return (NULL);
		res[i] = ft_atoi(st[i]);
		i--;
	}
	if (ft_has_dups(res, len))
	{
		free(res);
		return (NULL);
	}
	return (ft_indexate(res, len));
}
