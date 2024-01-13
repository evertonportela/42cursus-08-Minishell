/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:50:22 by evportel          #+#    #+#             */
/*   Updated: 2024/01/13 18:18:27 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*ft_create_token(char *content)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		ft_minishell_error(1, "malloc error");
	token->content = ft_strdup(content);
	if (!token->content)
		ft_minishell_error(1, "ft_strdup error");
	token->next = NULL;
	return (token);
}

void	ft_add_token(t_token **head, char *content)
{
	t_token	*new_token;

	new_token = ft_create_token(content);
	ft_lstadd_back((t_list **)head, (t_list *)new_token);
}

void	ft_tokenize_and_add(t_token **head, char *command_line)
{
	char	*token_content;

	token_content = ft_strtok(command_line, " ");
	while (token_content != NULL)
	{
		ft_add_token(head, token_content);
		token_content = ft_strtok(NULL, " ");
	}
}
