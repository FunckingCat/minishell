# Minishell

This implementation of the command shell copies all the basic functionality of the Bash shell - multiprocessor execution of binary files, support for file system navigation, standard input / output redirections, environment variables, pipelines.

## How to use it

Using make will create the minishell executable.

	make && ./minishell 

## Available options

Minishell runs executables from an absolute, relative or environment PATH (/bin/ls or ls), including arguments or options. ' and " work the same as bash, except for multiline commands.

You can separate commands with ;, as well as use redirections > >> < and pipes |.

Environment variables are handled, like $HOME, including the return code $?.

Finally, you can use Ctrl-C to interrupt and Ctrl-\ to quit a program, as well as Ctrl-D to throw an EOF, same as in bash.

A few of the functions are "built-in", meaning we don't call the executable, we re-coded them directly. It's the case for echo, pwd, cd, env, export, unset and exit.

	ᕙ(•ᴗ•)ᕗ ls
	builtin  constants.h  error  libft.a   minishell    minishell.h  parsing  README.md  res    signals  tests
	command  env          libft  Makefile  minishell.c  minishell.o  pipex    redirect   shell  tasks
	ᕙ(•ᴗ•)ᕗ pwd
	/home/david/minishell
	ᕙ(•ᴗ•)ᕗ cd
	ᕙ(•ᴗ•)ᕗ cat Makefile | grep NAME | wc -l
	5
	ᕙ(•ᴗ•)ᕗ cat <<q | cat -e | wc -l
	★ string one
	★ string two
	★ string three
	★ q
	3