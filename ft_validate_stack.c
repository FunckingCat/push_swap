/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:40:30 by unix              #+#    #+#             */
/*   Updated: 2021/11/08 21:08:06 by unix             ###   ########.fr       */
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

int	ft_validate_stack(char **st)
{
	int	i;

	while (*st)
	{
		if (**st == '0' && *(*st + 1) == '\0')
		{
			st++;
			continue ;
		}
		if (**st == '-' && *(*st + 1) == '1' && *(*st + 2) == '\0')
		{
			st++;
			continue ;
		}
		if (!ft_str_is_digit(*st))
			return (0);
		if (ft_atoi(*st) == -1 || ft_atoi(*st) == 0)
			return (0);
		st++;
	}
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
