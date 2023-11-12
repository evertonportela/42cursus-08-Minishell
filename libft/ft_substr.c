/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:26:07 by evportel          #+#    #+#             */
/*   Updated: 2023/05/11 21:00:48 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	index;
	size_t	src_lenght;

	if (!s)
		return (NULL);
	src_lenght = ft_strlen(s);
	if (start >= src_lenght)
		return (ft_strdup(""));
	if ((src_lenght - start) < len)
		len = src_lenght - start;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	index = 0;
	while ((s[index + start] != '\0') && (index < len))
	{
		substring[index] = s[start + index];
		index++;
	}
	substring[index] = '\0';
	return (substring);
}
