NAME = minishell
CC = gcc -g
#FLAGS = -Wall -Werror -Wextra
LIB = -L '.' -lft -lreadline

HEADER = 	./minishell.h \
			./shell/shell.h \
			./command/command.h \
			./gnl/get_next_line.h \
			./pipex/pipex.h \
			./redirect/redirect.h \
			./parsing/parsing.h \
			./env/env.h \
			./builtin/builtin.h \
			./error/error.h \
			./constants.h

MAIN =	./minishell.c

SHLL =	./shell/init_shell.c

CMD =	./command/new_command.c

GNL =	./gnl/get_next_line_utils.c \
		./gnl/get_next_line.c

PIPEX =	./pipex/pipex.c \
		./pipex/ft_exec.c

REDIR =	./redirect/new_redirect.c \
		./redirect/free_redirect.c

ENV =	./env/env_init.c \
		./env/env_contain.c \
		./env/env_get_par.c \
		./env/env_set_par.c \
		./env/env_del.c \
		./env/env_free.c

PARSE =	./parsing/parse_pipes.c \
		./parsing/parse_redirects.c

BUILT =	./builtin/env.c \
		./builtin/unset.c \
		./builtin/export.c \
		./builtin/pwd.c \
		./builtin/echo.c \
		./builtin/cd.c \
		./builtin/manage_builtin.c

ERROR =	./error/error.c

SRC = 	$(MAIN)		$(GNL)		$(PIPEX)	$(REDIR)	$(ENV) \
		$(PARSE)	$(BUILT)	$(ERROR)	$(SHLL)		$(CMD)

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
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) libft.a

leaks :	all
	leaks --at-Exit ./minishell

valgrind : all
	valgrind --leak-check=full ./minishell

re: fclean all

.PHONY: all clean fclean re leaks valgrind