/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:00:15 by evportel          #+#    #+#             */
/*   Updated: 2023/05/11 16:12:31 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	index;
	unsigned int	find;

	if (*little == '\0')
	{
		return ((char *) big);
	}
	index = 0;
	while (big[index] != '\0' && index < len)
	{
		find = 0;
		while (big[index + find] == little[find] && (index + find) < len)
		{
			find++;
			if (little[find] == '\0')
				return ((char *) &big[index]);
			else if (little[find] != big[index + find]
				|| big[index + find] == '\0')
				break ;
		}
		index++;
	}
	return (NULL);
}
