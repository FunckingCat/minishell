NAME = minishell
CC = gcc -g
#FLAGS = -Wall -Werror -Wextra
LIB = -L '.' -lft -lreadline

HEADER = 	./minishell.h \
			./shell.h \
			./gnl/get_next_line.h \
			./pipex/pipex.h \
			./redirect/redirect.h \
			./parsing/parsing.h \
			./env/env.h \
			./builtin/builtin.h \
			./error/error.h \
			./constants.h

MAIN =	./minishell.c

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
		./builtin/pwd.c 

ERROR =	./error/error.c

SRC = 	$(MAIN)		$(GNL)		$(PIPEX)	$(REDIR)	$(ENV) \
		$(PARSE)	$(BUILT)	$(ERROR)

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

re: fclean all

.PHONY: all clean fclean re