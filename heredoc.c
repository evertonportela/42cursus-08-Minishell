/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:20:57 by evportel          #+#    #+#             */
/*   Updated: 2023/11/12 13:26:23 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	const char	*text;

	text = "Este é um exemplo de heredoc em C.\n"
		"Você pode incluir grandes blocos de texto\n"
		"de uma maneira mais legível e formatada.\n"
		"Isso facilita a escrita de strings longas.";
	printf("%s\n", text);
	return (0);
}

/*
* caso de uso em versões anteriores do C99

int	main(void)
{
	const char	texto[] = "Este é um exemplo de heredoc em C.\n"
		"Você pode incluir grandes blocos de texto\n"
		"de uma maneira mais legível e formatada.\n"
		"Isso facilita a escrita de strings longas.";

	printf("%s\n", texto);
	return (0);
}

*/