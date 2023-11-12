/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:40:40 by evportel          #+#    #+#             */
/*   Updated: 2023/05/26 21:07:16 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb == 0 && size == 0)
		return (allocated = malloc(total_size));
	if (nmemb != 0 && (total_size / nmemb) != size)
		return (NULL);
	allocated = malloc(total_size);
	if (allocated != NULL)
	{
		ft_bzero(allocated, nmemb * size);
	}
	return (allocated);
}
