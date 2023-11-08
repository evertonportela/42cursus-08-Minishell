/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:03:12 by evportel          #+#    #+#             */
/*   Updated: 2023/11/05 22:25:16 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(int argc, char **argv)
int	main(void)
{
	char	*res;

	while (1)
	{
		res = readline("ostra > ");
		if (res == NULL)
			exit(1);
		if (res[0] == '\0')
			exit(1);
		printf("%s\n", res);
	}
	return (EXIT_SUCCESS);
}
