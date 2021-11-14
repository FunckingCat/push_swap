/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:40 by unix              #+#    #+#             */
/*   Updated: 2021/11/14 17:46:04 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

//VALIDATE
int		ft_validate_stack(char **st);
int		ft_has_dups(int *arr, int len);
int		ft_is_sorted(int *arr, int direction);

//UTILS
int		ft_min_arr(int *arr, int len);
int		ft_max_arr(int *arr, int len);

//STACK UTILS
int		ft_slen(int *stack);
void	ft_swap_val(int *d1, int *d2);

//SORTING FUNCTIONS
void	ft_sort(int *arr);

//MOVE FUNCTIONS
void	ft_swap(char mode, int *st_a, int *st_b);
void	ft_push(char mode, int *st_a, int *st_b);
void	ft_rotate(char mode, int *st_a, int *st_b);
void	ft_rev_rotate(char mode, int *st_a, int *st_b);

#endif