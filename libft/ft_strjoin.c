/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:40:31 by evportel          #+#    #+#             */
/*   Updated: 2023/05/12 16:54:43 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	count;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!new_str)
		return (NULL);
	count = 0;
	while (count < ft_strlen(s1))
	{
		new_str[count] = s1[count];
		count++;
	}
	index = 0;
	while (count < (ft_strlen(s1) + ft_strlen(s2)))
	{
		new_str[count] = s2[index];
		count++;
		index++;
	}
	new_str[count] = '\0';
	return (new_str);
}
