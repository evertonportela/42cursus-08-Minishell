/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:03:12 by evportel          #+#    #+#             */
/*   Updated: 2023/12/02 19:49:41 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
		char **env)
{
	char		*command_line;
	char		*prompt;
	t_minishell	*minishell;

	minishell = ft_minishell_init(env);
	if (!minishell)
	{
		perror("Malloc error");
		exit(EXIT_FAILURE);
	}
	minishell->tokens = NULL;
	prompt = ft_strjoin(ft_get_local_user(env), "@massunim: $ ");
	while (1)
	{
		command_line = readline(prompt);
		if (ft_analyzer_command(command_line) == EXIT_SUCCESS)
		{
			ft_tokenize_and_add(&minishell->tokens, command_line);
			ft_executor_command(env, command_line);
			// ft_executor_command(env, &minishell->tokens->content[0]);
		}
		free(command_line);
	}
	return (EXIT_SUCCESS);
}
