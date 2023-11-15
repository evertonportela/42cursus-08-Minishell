/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:03:12 by evportel          #+#    #+#             */
/*   Updated: 2023/11/15 10:58:34 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_clean_mult_allocations(char **arrays)
{
	int	index;

	index = 0;
	while (arrays[index] != NULL)
	{
		free(arrays[index]);
		index++;
	}
	free(arrays);
	if (arrays != NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(void)
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
			printf("exit\n");
			status = 1;
		}
		free(prompt_line);
	}
	return (EXIT_SUCCESS);
}
