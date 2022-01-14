# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unix <unix@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2022/01/14 12:03:51 by unix             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = 
#FLAGS = -Wall -Werror -Wextra
LIB = -L '.' -lft 

HEADER = minishell.h

SRC = minishell.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	make bonus -C ./libft
	cp libft/libft.a ./
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C ./libft
	$(RM) $(OBJ) $(BONUS_OBJ_FILES)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re bonus