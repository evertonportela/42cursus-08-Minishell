/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:21:22 by evportel          #+#    #+#             */
/*   Updated: 2024/01/13 18:26:36 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim)
/**
 * @brief 
 * Divide uma string em uma série de tokens usando o delimitador fornecido.
 * Mantém o rastreamento da última posição encontrada
 * Se a chamada é com uma nova string, redefine o ponteiro
 * Se a chamada é sem uma nova string, continua da última posição encontrada
 * Procura pelo próximo delimitador na string
 * Se um delimitador foi encontrado, substitui por '\0'
 * Atualiza a última posição encontrada
 * Se nenhum delimitador foi encontrado, chegamos ao final da string
*/
{
	char		*token_start;
	char		*delim_pos;
	static char	*last_token;

	last_token = NULL;
	if (str != NULL)
	{
		last_token = str;
	}
	else
	{
		if (last_token == NULL)
			return (NULL);
	}
	token_start = last_token;
	delim_pos = ft_strpbrk(last_token, delim);
	if (delim_pos != NULL)
	{
		*delim_pos = '\0';
		last_token = delim_pos + 1;
	}
	else
		last_token = NULL;
	return (token_start);
}
