/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:12:04 by evportel          #+#    #+#             */
/*   Updated: 2023/05/08 11:09:45 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long int	count;

	if (src == NULL && dest == NULL)
	{
		return (NULL);
	}
	if (dest < src)
	{
		count = 0;
		while (count < n)
		{
			((char *) dest)[count] = ((char *) src)[count];
			count++;
		}
	}
	else
	{
		count = n;
		while (count > 0)
		{
			((char *) dest)[count - 1] = ((char *) src)[count - 1];
			count--;
		}
	}
	return (dest);
}
