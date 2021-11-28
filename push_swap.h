/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unix <unix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:23:40 by unix              #+#    #+#             */
/*   Updated: 2021/11/28 19:04:26 by unix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

//RAISE ERROR
void	ft_raise_error(int	*st_a, int *st_b);

//PARSE
int		*ft_parse_stack(char **st, int len);
int		ft_is_sorted(int *arr, int direction);

//UTILS
int		ft_slen(int *stack);
int		ft_top(int	*st, int pos);
int		ft_min_arr(int *arr, int len);
int		ft_max_arr(int *arr, int len);
int		ft_index(int val, int *stack);

//MOVE FUNCTIONS
void	ft_swap_val(int *d1, int *d2);
void	ft_swap(char mode, int *st_a, int *st_b);
void	ft_push(char mode, int *st_a, int *st_b);
void	ft_rotate(char mode, int *st_a, int *st_b);
void	ft_rev_rotate(char mode, int *st_a, int *st_b);

//SOLVE
int		ft_score(int *st_a, int *st_b);
void	ft_solve_small(int *st_a, int *st_b);
void	ft_solve_common(int *st_a, int *st_b);

#endif