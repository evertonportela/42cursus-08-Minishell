/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:35:33 by evportel          #+#    #+#             */
/*   Updated: 2023/05/06 16:57:24 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	c = (unsigned char)c;
	if (s[index] == 0)
		return ((char *)s);
	while (s[index])
	{
		if (s[index] == c)
		{
			return ((char *)s + index);
		}
		else if (s[index + 1] == c)
		{
			return ((char *)s + (index + 1));
		}
		index++;
	}
	return (NULL);
}
