# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2022/01/27 12:15:43 by tyamcha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
FLAGS = 
#FLAGS = -Wall -Werror -Wextra
LIB = -L '.' -lft -lreadline

HEADER = 	./minishell.h \
			./gnl/get_next_line.h \
			./pipex/pipex.h \
			./redirect/redirect.h \
			./parsing/parsing.h

SRC = 	./minishell.c \
		./gnl/get_next_line_utils.c ./gnl/get_next_line.c \
		./pipex/pipex.c ./pipex/ft_exec.c ./pipex/ft_env.c \
		./error.c \
		./redirect/new_redirect.c ./redirect/free_redirect.c \
		./parsing/parse_pipes.c

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

.PHONY: all clean fclean re