# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 17:38:20 by eescalei          #+#    #+#              #
#    Updated: 2024/03/10 23:55:05 by eescalei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc 
FLAGS = -Wall -Wextra -Werror
SRCF = main.c \
		innit_data.c \
		list_funcs.c

SRC = $(addprefix src/, $(SRCF))
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 