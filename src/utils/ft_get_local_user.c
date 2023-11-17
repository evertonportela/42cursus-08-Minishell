/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_local_user.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:49:22 by evportel          #+#    #+#             */
/*   Updated: 2023/11/15 19:09:40 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_get_local_user(char **env)
{
	int		index;
	char	*user;

	index = 0;
	while (env[index] && ft_strncmp(env[index], "USER=", 5))
		index++;
	if (!env[index])
		return (NULL);
	user = env[index] + 5;
	return (user);
}
