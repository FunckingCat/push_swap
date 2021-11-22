# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unix <unix@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2021/11/22 16:17:25 by unix             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = gcc
#FLAGS = 
FLAGS = -Wall -Werror -Wextra
LIB = -L '.' -lft 

HEADER = push_swap.h checker.h

COMMON = ft_utils.c ft_validate_stack.c ft_stack_utils.c \
			ft_move.c 
MAIN = main.c ft_solve_uniqe.c ft_solve_common.c ft_sort.c
BONUS = checker.c

MAIN_FILES = $(MAIN) $(COMMON)
BONUS_FILES = $(BONUS) $(COMMON)

MAIN_OBJ_FILES = $(MAIN_FILES:.c=.o)
BONUS_OBJ_FILES = $(BONUS_FILES:.c=.o)

RM = rm -f

all: $(NAME)

bonus: $(BONUS_NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(MAIN_OBJ_FILES) $(HEADER)
	make bonus -C ./libft
	cp libft/libft.a ./
	$(CC) $(FLAGS) -o $(NAME) $(MAIN_OBJ_FILES) $(LIB)

$(BONUS_NAME): $(BONUS_OBJ_FILES) $(HEADER)
	make bonus -C ./libft
	cp libft/libft.a ./
	$(CC) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJ_FILES) $(LIB)

clean:
	make clean -C ./libft
	$(RM) $(MAIN_OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(BONUS_NAME) libft.a

re: fclean all

.PHONY: all clean fclean re bonus