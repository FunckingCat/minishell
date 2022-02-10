/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:36:15 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:36:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define MINISHELL	"minishell"
# define PROMPT		"ᕙ(•ᴗ•)ᕗ "
# define REDIRECT	"★ "

// Parsing constants
# define Q_NCL			"quotes are not closed"
# define SYNTAX_PIPE	"syntax error near unexpected token '|'"
# define MALLOC_ERR		"malloc error"
# define DIR_CURRENT	"./"
# define DIR_PREV		"../"

// Env constants
# define ENV		"env"
# define ENV_MALLOC	"malloc error" 
# define ENV_NO_PAR	"some paramets are NULL"

// Redirect constants
# define RD			"redirect"
# define RD_FAIL	"invalid params"
# define RD_FD_NF	"No such file or directory"
# define RD_FD_PD	"Permission denied"
# define RD_FD_FR	"File read failed"
# define RD_FD_FC	"File create failed"
# define RD_ERR_T	"syntax error near unexpected token '<'"
# define PIPE		"pipe"
# define PIPE_FAIL	"failed create a pipe"
# define RD_RAD_FL	"failed to read input"

// Redirect types
# define RD_IN		1
# define RD_DIN		2
# define RD_OUT		3
# define RD_DOUT	4

// Builtin massages
# define EXIT			"exit"
# define EXP			"export"
# define UNS			"unset"
# define EXP_NOT_VALID	"not a valid identifier"
# define CD				"cd"
# define CD_NO_FILE		"No such file or directory"
# define CD_MN_ARGS		"too many arguments"
# define ENV_NO_FILE	"No such file or directory"
# define NO_ENV			"env is corrupted"

// Exit
# define EXIT			"exit"
# define EXIT_ERR_ARGS	"numeric argument required"
# define EXIT_ERR_NUM	"too many arguments"

//PIPEX
# define PATH			"PATH"
# define DUP			"dup2"
# define DUP_FAIL		"dup failed"
# define FORK			"fork"
# define FORK_FAIL		"fork failed"
# define CMD_NF			"command not found"
# define IS_DIR			"is a directory"

#endif