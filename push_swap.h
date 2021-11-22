/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:40 by unix              #+#    #+#             */
/*   Updated: 2021/11/22 15:06:11 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

//TO DELETE
void	print_stacks(int *st_a, int *st_b);

//RAISE ERROR
void	ft_raise_error();

//VALIDATE
int		ft_validate_stack(char **st);
int		ft_str_is_digit(char *str);
int		ft_has_dups(int *arr, int len);
int		ft_is_sorted(int *arr, int direction);

//UTILS
int		ft_min_arr(int *arr, int len);
int		ft_max_arr(int *arr, int len);
int		ft_in(int elem, int min, int max);

//STACK UTILS
int		ft_slen(int *stack);
int		ft_index(int val, int *stack);
void	ft_swap_val(int *d1, int *d2);
int		*ft_indexate(int *arr, int len);
int		*ft_parse_stack(char **st, int len);
void	free_char_arr(char **st);

//SORTING FUNCTIONS
void	ft_sort(int *arr);

//MOVE FUNCTIONS
void	ft_swap(char mode, int *st_a, int *st_b);
void	ft_push(char mode, int *st_a, int *st_b);
void	ft_rotate(char mode, int *st_a, int *st_b);
void	ft_rev_rotate(char mode, int *st_a, int *st_b);

//SOLVE
void	ft_solve_three(int *st);
void	ft_solve_four(int *st_a, int *st_b);
void	ft_solve_five(int *st_a, int *st_b);
void	ft_solve_common(int *st_a, int *st_b);

#endif