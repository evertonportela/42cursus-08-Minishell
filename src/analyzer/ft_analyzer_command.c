/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyzer_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:50:48 by evportel          #+#    #+#             */
/*   Updated: 2023/11/22 21:58:02 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_check_single_quotes(char *command_line)
{
	int		count_quote;
	int		index;

	count_quote = 0;
	index = 0;
	while (command_line[index] != '\0')
	{
		if (command_line[index] == '\"')
			count_quote++;
		index++;
	}
	if ((count_quote % 2) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_check_double_quotes(char *command_line)
{
	int		count_quote;
	int		index;

	count_quote = 0;
	index = 0;
	while (command_line[index] != '\0')
	{
		if (command_line[index] == '\'')
			count_quote++;
		index++;
	}
	if ((count_quote % 2) == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	ft_analyzer_command(char *command_line)
{
	if (ft_check_single_quotes(command_line) == EXIT_FAILURE)
	{
		ft_minishell_error(2, "syntax error: unexpected end of file");
		return (EXIT_FAILURE);
	}
	else if (ft_check_double_quotes(command_line) == EXIT_FAILURE)
	{
		ft_minishell_error(2, "syntax error: unexpected end of file");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
