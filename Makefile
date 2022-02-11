# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: david <david@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 18:36:19 by david             #+#    #+#              #
#    Updated: 2022/02/11 14:30:36 by david            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc -g
FLAGS = -Wall -Werror -Wextra
LIB = -L '.' -lft -lreadline

HEADER = 	./minishell.h \
			./shell/shell.h \
			./command/command.h \
			./pipex/pipex.h \
			./redirect/redirect.h \
			./parsing/parsing.h \
			./env/env.h \
			./builtin/builtin.h \
			./error/error.h \
			./constants.h \
			./signals/signals.h

MAIN =	./minishell.c

SIGNALS = ./signals/signal_handlers.c

SHLL =	./shell/init_shell.c

CMD =	./command/new_command.c

PIPEX =	./pipex/pipex.c \
		./pipex/ft_exec.c

REDIR =	./redirect/new_redirect.c \
		./redirect/free_redirect.c

ENV =	./env/env_init.c \
		./env/env_contain.c \
		./env/env_get_par.c \
		./env/env_set_par.c \
		./env/env_del.c

PARSE =	./parsing/parse_pipes.c \
		./parsing/parse_redirects.c \
		./parsing/parse_abs_path.c \
		./parsing/parse_cmd_name.c \
		./parsing/parse_beautify.c \
		./parsing/parse_global.c \
		./parsing/parse_command.c

BUILT =	./builtin/env.c \
		./builtin/unset.c \
		./builtin/export.c \
		./builtin/pwd.c \
		./builtin/echo.c \
		./builtin/cd.c \
		./builtin/run_builtin.c

ERROR =	./error/error.c \
		./error/error_ext.c

SRC = 	$(MAIN)		$(SHLL)     $(PIPEX)	$(REDIR)	$(ENV) \
		$(PARSE)	$(BUILT)	$(ERROR)	$(CMD) 		$(SIGNALS)

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE_LBR)

$(NAME): $(OBJ) $(HEADER)
	make bonus -C ./libft
	cp libft/libft.a ./
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIB) $(SYS_LBR)

clean:
	make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) libft.a

leaks :	all
	leaks --at-Exit ./minishell

valgrind : all
	valgrind --leak-check=full --show-leak-kinds=all ./minishell

re: fclean all

.PHONY: all clean fclean re leaks valgrind
