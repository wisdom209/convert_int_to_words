# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 20:22:22 by coder             #+#    #+#              #
#    Updated: 2023/03/19 20:26:23 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra
SRC=ft_atoi.c get_string_struct.c main.c print_functions_one.c print_functions_two.c split_string.c string_functions.c string_handling.c
OBJ=$(patsubst %c,%o,$(SRC))
RM=rm -f
NAME=rush-02

all:$(OBJ)
	$(CC)	$(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS)	-c -o $@ $^

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

clean:
	$(RM) *~ $(NAME)

re: oclean all
