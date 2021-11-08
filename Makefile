# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unix <unix@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2021/11/08 19:41:48 by unix             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = 
#FLAGS = -Wall -Werror -Wextra
LIB = -L '.' -lft 

HEADER = push_swap.h
SRC_FILES = push_swap.c ft_utils.c ft_validate_stack.c

OBJ_FILES = $(SRC_FILES:.c=.o)
RM = rm -f

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) $(HEADER)
	make bonus -C ./libft
	cp libft/libft.a ./
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILES) $(LIB)

clean:
	make clean -C ./libft
	$(RM) $(OBJ_FILES)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re