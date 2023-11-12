/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:59:22 by evportel          #+#    #+#             */
/*   Updated: 2023/05/11 16:06:34 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			index;

	m1 = (unsigned char *) s1;
	m2 = (unsigned char *) s2;
	index = 0;
	while (index < n)
	{
		if (*m1 != *m2)
		{
			return (*m1 - *m2);
		}
		m1++;
		m2++;
		index++;
	}
	return (0);
}
