/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:03:12 by evportel          #+#    #+#             */
/*   Updated: 2023/11/12 17:49:48 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_parser(char *content)
{
	char	**single_line_commands;

	/* Divide a string do comando em argumentos individuais */
	single_line_commands = ft_split(content, ' ');
	return (single_line_commands);
}

int	main(void)
{
	char	*res;
	char	**single_line_commands;

	while (1)
	{
		res = readline("ostra > ");
		if (res == NULL
		)
			exit(1);
		if (res[0] == '\0')
			exit(1);
		if (ft_strncmp(res, "exit", 4) == 0)
		{
			printf("exit\n");
			exit(1);
		}
		single_line_commands = ft_parser(res);
	}
	return (EXIT_SUCCESS);
}
