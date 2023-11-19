/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:03:12 by evportel          #+#    #+#             */
/*   Updated: 2023/11/18 23:32:19 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_single_quotes(char *command_line)
{
	int	count_quote;
	int	index;

	count_quote = 0;
	index = 0;
	while (command_line[index++] != '\0')
	{
		if (command_line[index] == '\'')
			count_quote++;
	}
	if ((count_quote % 2) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
		char **env)
{
	char	*command_line;
	char	*prompt;
	int		pid;

	prompt = ft_strjoin(ft_get_local_user(env), "@minishell: $ ");
	while (1)
	{
		command_line = readline(prompt);
		if (ft_strncmp(command_line, "exit", 4) == 0)
			break ;
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
	}
	free(prompt);
	ft_printf("exit\n");
	return (EXIT_SUCCESS);
}
