# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmika <wmika@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:23:43 by unix              #+#    #+#              #
#    Updated: 2022/01/27 21:02:08 by wmika            ###   ########.fr        #
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
			./env/env.h \
			./redirect/redirect.h \
			./builtin/builtin.h \
			./error/error.h \
			./constants.h

SRC = 	./minishell.c \
		./gnl/get_next_line_utils.c ./gnl/get_next_line.c \
		./pipex/pipex.c ./pipex/ft_exec.c ./pipex/ft_env.c \
		./error/error.c \
		./env/env_init.c ./env/env_contain.c ./env/env_get_par.c \
		./env/env_set_par.c ./env/env_del.c ./env/env_free.c \
		./redirect/new_redirect.c ./redirect/free_redirect.c \
		./builtin/env.c ./builtin/unset.c ./builtin/export.c \
		./builtin/pwd.c 


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