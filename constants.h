#ifndef CONSTANTS_H
# define CONSTANTS_H

# define MINISHELL	"minishell"
# define PROMPT		"MINISHELL > "

// Console colors
# define RED	"\001\033[0;31m\002"
# define GREEN	"\001\033[0;32m\002"
# define YELLOW	"\001\033[0;33m\002"
# define BLUE	"\001\033[0;34m\002"
# define PURPLE	"\001\033[0;35m\002"
# define NONE	"\001\033[0m\002"

// Parsing constants
# define Q_NCL			"quotes are not closed"
# define SYNTAX_PIPE	"syntax error near unexpected token '|'"
# define MALLOC_ERR		"malloc error"
# define DIR_CURRENT	"./"
# define DIR_PREV		"../"

// Env constants
# define ENV		"env"
# define ENV_MALLOC	"malloc error" 
# define ENV_NO_PAR	"no parameters"

// Redirect constants
# define RD			"redirect"
# define RD_FAIL	"invalid params"
# define RD_FD_NF	"No such file or directory"
# define RD_FD_PD	"Permission denied"
# define RD_FD_FR	"File read failed"
# define RD_FD_FC	"File create failed"
# define RD_ERR_T	"syntax error near unexpected token '<'"

// Redirect types
# define RD_IN		1
# define RD_DIN		2
# define RD_OUT		3
# define RD_DOUT	4

// Builtin errors
# define EXP "Export"
# define EXP_NOT_VALID "not a valid identifier"
# define CD "cd"
# define CD_NO_FILE "No such file or directory"
# define CD_MN_ARGS "too many arguments"
# define ENV_NO_FILE "No such file or directory"

#endif