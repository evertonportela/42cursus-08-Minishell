/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:15:58 by evportel          #+#    #+#             */
/*   Updated: 2023/12/02 21:03:52 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_minishell	*ft_minishell_init(char **env __attribute__((unused)))
{
	t_minishell	*minishell;

	minishell = ft_calloc(1, sizeof(t_minishell));
	return (minishell);
}
