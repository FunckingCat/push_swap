/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:40 by unix              #+#    #+#             */
/*   Updated: 2021/11/13 20:22:50 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

//VALIDATE
int	ft_validate_stack(char **st);
int	ft_has_dups(int *arr, int len);
int	ft_is_sorted(int *arr, int direction);

//UTILS
int	ft_min_arr(int *arr, int len);
int	ft_max_arr(int *arr, int len);


#endif