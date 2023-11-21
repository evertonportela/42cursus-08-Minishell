/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyzer_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:50:48 by evportel          #+#    #+#             */
/*   Updated: 2023/11/20 23:25:38 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_single_quotes(char *command_line)
{
	int		count_quote;
	int		index;

	count_quote = 0;
	index = 0;
	while (command_line[index] != '\0')
	{
		if (command_line[index] == '\'')
		{
			count_quote++;
		}
		index++;
	}
	if ((count_quote % 2) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_analyzer_command(char **env, char *command_line)
{
	pid_t	pid;

	if (ft_check_single_quotes(command_line) == EXIT_FAILURE)
	{
		ft_minishell_error(2, "syntax error: unexpected end of file");
		return (EXIT_FAILURE);
	}
	else
	{
		pid = fork();
		if (pid < 0)
			ft_minishell_error(1, "error setting pid");
		if (pid == 0)
		{
			if (ft_exec_command(command_line, env) == EXIT_FAILURE)
				ft_minishell_error(127, "");
		}
		else
			waitpid(pid, NULL, 0);
		return (EXIT_SUCCESS);
	}
}
