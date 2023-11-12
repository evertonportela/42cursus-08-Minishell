/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:15:10 by evportel          #+#    #+#             */
/*   Updated: 2023/05/14 21:24:58 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char cut)
{
	size_t	words;

	words = 0;
	if (*str == '\0')
		return (words);
	if (cut == '\0')
		return (1);
	while (*str == cut && *str)
		str++;
	while (*str)
	{
		words++;
		while (*str != cut && *str)
			str++;
		while (*str == cut && *str)
			str++;
	}
	return (words);
}

void	*go_back(char **slices)
{
	while (*slices)
		free(*slices);
	free(slices);
	return (NULL);
}

char	**constructor_word(char **slices, const char *str, char cut)
{
	size_t	len_word;
	size_t	index;

	index = 0;
	while (*str)
	{
		len_word = 0;
		while (str[len_word] != cut && str[len_word])
			len_word++;
		slices[index] = (char *) malloc(len_word * sizeof(char) + 1);
		if (slices[index] == NULL)
			return (go_back(slices));
		slices[index][len_word] = '\0';
		while (len_word > 0)
		{
			slices[index][len_word - 1] = str[len_word - 1];
			len_word--;
		}
		while (*str != cut && *str)
			str++;
		while (*str == cut && *str)
			str++;
		index++;
	}
	return (slices);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**array;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **) malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (*s == c && *s)
		s++;
	array = constructor_word(array, s, c);
	array[words] = NULL;
	return (array);
}
