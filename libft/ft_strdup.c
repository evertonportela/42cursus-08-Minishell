/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:43:56 by evportel          #+#    #+#             */
/*   Updated: 2023/05/11 16:08:08 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char			*new_str;
	unsigned int	lenght;

	lenght = ft_strlen(str);
	new_str = ft_calloc(lenght + 1, sizeof(const char));
	if (new_str == NULL)
	{
		return (NULL);
	}
	new_str = ft_memcpy(new_str, str, lenght);
	return (new_str);
}
