/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:03:12 by evportel          #+#    #+#             */
/*   Updated: 2023/11/22 21:58:34 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
		char **env)
{
	char	*command_line;
	char	*prompt;

	prompt = ft_strjoin(ft_get_local_user(env), "@massunim: $ ");
	while (1)
	{
		command_line = readline(prompt);
		if (ft_analyzer_command(command_line) == EXIT_SUCCESS)
			ft_executor_command(env, command_line);
		free(command_line);
	}
	return (EXIT_SUCCESS);
}
