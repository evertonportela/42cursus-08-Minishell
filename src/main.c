/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:03:12 by evportel          #+#    #+#             */
/*   Updated: 2023/11/15 18:03:38 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
		char **env)
{
	char	*prompt_line;
	int		status;
	int		pid;

	status = 0;
	while (status == 0)
	{
		prompt_line = readline("tt@sururu: $ ");
		if (ft_strncmp(prompt_line, "exit", 4) == 0)
		{
			ft_printf("exit\n");
			return (EXIT_SUCCESS);
		}
		pid = fork();
		if (pid < 0)
			ft_minishell_error(1, "error setting pid");
		if (pid == 0)
		{
			if (ft_exec_command(prompt_line, env) == EXIT_FAILURE)
				ft_printf("Fail :(\n");
			free(prompt_line);
			exit(1);
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
		status = 0;
	}
	return (EXIT_SUCCESS);
}
