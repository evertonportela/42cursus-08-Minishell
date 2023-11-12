/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:04 by evportel          #+#    #+#             */
/*   Updated: 2023/05/09 11:15:46 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	count;

	len_src = ft_strlen(src);
	len_dest = 0;
	while (dest[len_dest] && len_dest < size)
	{
		len_dest++;
	}
	count = 0;
	if (len_dest < size)
	{
		while ((count + len_dest) < (size - 1) && src[count] != '\0')
		{
			dest[count + len_dest] = src[count];
			count++;
		}
		dest[count + len_dest] = '\0';
	}
	return (len_dest + len_src);
}
