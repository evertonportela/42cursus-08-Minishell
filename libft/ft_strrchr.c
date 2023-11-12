/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:35:33 by evportel          #+#    #+#             */
/*   Updated: 2023/05/26 17:34:17 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*matched;
	unsigned char	*str;

	str = (unsigned char *)s;
	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)(str + ft_strlen((char *)str)));
	matched = 0;
	while (*str)
	{
		if (*str == c)
			matched = str;
		str++;
	}
	return ((char *)(matched));
}
