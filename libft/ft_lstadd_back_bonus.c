/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:27:48 by evportel          #+#    #+#             */
/*   Updated: 2023/05/28 18:09:27 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end_ptr;
	t_list	*ptr_aux;

	ptr_aux = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		end_ptr = ft_lstlast(ptr_aux);
		end_ptr->next = new;
	}
}
