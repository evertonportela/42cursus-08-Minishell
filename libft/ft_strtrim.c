/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:08:52 by evportel          #+#    #+#             */
/*   Updated: 2023/05/12 16:56:44 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		foot;
	const char	*str_empty;

	if (!s1 || !set)
		return (NULL);
	foot = ft_strlen(s1);
	str_empty = "";
	if (s1 == str_empty || set == str_empty)
	{
		return (ft_substr(s1, 0, foot + 1));
	}
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	foot = ft_strlen(s1);
	while (foot && ft_strchr(set, s1[foot]))
	{
		foot--;
	}
	return (ft_substr(s1, 0, foot + 1));
}
