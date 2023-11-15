/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:19 by evportel          #+#    #+#             */
/*   Updated: 2023/11/15 12:42:54 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pipex_error(int cod_exit, char *str)
{
	write(2, "PipexError: ", 12);
	if (cod_exit == 127)
		write(2, "command not found", 18);
	else
		write(2, strerror(cod_exit), ft_strlen(strerror(cod_exit)));
	if (str[0] != 0)
	{
		write(2, ": ", 2);
		write(2, &str[0], ft_strlen(&str[0]));
	}
	write(2, "\n", 1);
	if (cod_exit == 0)
		exit(cod_exit);
	else
		exit(EXIT_FAILURE);
}
