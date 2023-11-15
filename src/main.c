/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:03:12 by evportel          #+#    #+#             */
/*   Updated: 2023/11/15 13:12:23 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
		char **env)
{
	char	*prompt_line;
	int		status;

	status = 0;
	while (status == 0)
	{
		prompt_line = readline("cadet@sururu: $ ");
		if (prompt_line == NULL)
			exit(1);
		if (prompt_line[0] == '\0')
			exit(1);
		if (ft_strncmp(prompt_line, "exit", 4) == 0)
		{
			ft_printf("exit\n");
			status = 1;
		}
		if (ft_exec_command(prompt_line, env) == EXIT_FAILURE)
		{
			ft_printf("Fail :(\n");
		}
		free(prompt_line);
	}
	return (EXIT_SUCCESS);
}
