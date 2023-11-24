/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:19 by evportel          #+#    #+#             */
/*   Updated: 2023/11/23 21:53:05 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_minishell_error(int cod_exit, char *str)
{
	write(2, "massunim: ", 11);
	write(2, &str[0], ft_strlen(&str[0]));
	write(2, "\n", 1);
	errno = cod_exit;
}

// if (cod_exit == 127)
// {
// 	write(2, "command not found\n", 19);
// 	exit(127);
// }
// else
// 	write(2, strerror(cod_exit), ft_strlen(strerror(cod_exit)));
// if (str[0] != 0)
// {
// 	write(2, ": ", 2);
// 	write(2, &str[0], ft_strlen(&str[0]));
// }