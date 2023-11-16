/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_mult_allocations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:03:51 by evportel          #+#    #+#             */
/*   Updated: 2023/11/15 21:10:02 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
	return (EXIT_SUCCESS);
}
