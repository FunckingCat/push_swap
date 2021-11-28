/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:40:30 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 18:43:25 by unix             ###   ########.fr       */
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
	int	i;

	if (ft_has_dups(arr, len))
	{
		free(arr);
		return (NULL);
	}
	i = 0;
	res = malloc((len + 1) * sizeof(int));
	if (!res)
	{
		free(arr);
		return (NULL);
	}
	res[ft_min_arr(arr, len)] = len - 1;
	arr[ft_min_arr(arr, len)] = INT_MIN;
	while (i < len - 1)
	{
		res[ft_max_arr(arr, len)] = i++;
		arr[ft_max_arr(arr, len)] = INT_MIN;
	}
	res[len] = -1;
	free(arr);
	return (res);
}

int	*ft_parse_stack(char **st, int len)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(len * sizeof(int));
	if (!res)
		return (NULL);
	while (i < len)
	{
		if (!ft_str_is_digit(st[i]))
			return (NULL);
		else if (st[len - 1 - i][0] == '0' && st[len - 1 - i][1] == '\0')
			res[i] = 0;
		else if (st[len - 1 - i][0] == '-' && st[len - 1 - i][1] == '1'
			&& st[len - 1 - i][2] == '\0')
			res[i] = -1;
		else if (ft_atoi(st[len - 1 - i]) == -1
			|| ft_atoi(st[len - 1 - i]) == 0)
			return (NULL);
		res[i] = ft_atoi(st[len - 1 - i]);
		i++;
	}
	return (ft_indexate(res, len));
}
