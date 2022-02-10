/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:36:22 by david             #+#    #+#             */
/*   Updated: 2022/02/10 18:36:23 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_exit(t_shell *shell)
{
	int		i;
	char	**sp;

	i = 0;
	if (shell->cmds != 1)
		return ;
	sp = ft_split(shell->cmds_arr[0]->input, ' ');
	while (sp[i])
		i++;
	if (!ft_strcmp(sp[0], EXIT))
	{
		shell->exit = 1;
		if (i > 1)
			shell->exit_status = ft_atoi(sp[1]);
		if (i > 1 && !ft_isstrdigit(sp[1]))
		{
			put_ext_error(EXIT, sp[1], EXIT_ERR_ARGS);
			shell->exit_status = 255;
		}
		else if (i > 2)
		{
			shell->exit = 0;
			put_error(EXIT, EXIT_ERR_NUM);
		}
	}
}

void	routine(t_shell *shell, char *cmd)
{
	char	**parse;
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup(cmd);
	str = parse_beautify(str);
	str = parse_global(str, shell->env);
	parse = parse_pipes(str);
	if (!parse)
		return ;
	while (*(parse + shell->cmds))
		shell->cmds++;
	shell->cmds_arr = ft_malloc(sizeof(t_cmd *) * shell->cmds);
	while (i < shell->cmds)
	{
		shell->cmds_arr[i] = new_cmd(ft_strtrim(parse[i], " \t"));
		i++;
	}
	check_exit(shell);
	pipex(shell);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*read;
	char	*str;

	g_heap.ptr = (void *)&shell;
	if (init_shell(&shell, envp))
		return (1);
	signal(SIGQUIT, SIG_IGN);
	while (!shell.exit)
	{
		shell.cmds = 0;
		signal(SIGINT, sig_int_empty);
		read = readline(PROMPT);
		if (check_exit_ctrl_d(read))
			break ;
		if (check_int_skip(&shell, read))
			continue ;
		if (ft_strlen(read) > 0)
			add_history(read);
		routine(&shell, read);
		free(read);
	}
	ft_free();
	return (shell.exit_status);
}
