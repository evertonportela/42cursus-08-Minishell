/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:33:02 by evportel          #+#    #+#             */
/*   Updated: 2024/01/13 18:35:58 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str, const char *charset)
/**
 * @brief 
 * Procura na string 'str' a primeira ocorrência de qualquer caractere
 * Itera sobre os caracteres de 'str'
 * Itera sobre os caracteres de 'charset'
 * Retorna o ponteiro para a primeira ocorrência encontrada
 * Nenhum caractere encontrado
*/
{
	const char	*char_in_charset;

	while (*str != '\0')
	{
		char_in_charset = charset;
		while (*char_in_charset != '\0')
		{
			if (*str == *char_in_charset)
			{
				return ((char *)str);
			}
			char_in_charset++;
		}
		str++;
	}
	return (NULL);
}
