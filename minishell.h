/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:25:08 by evportel          #+#    #+#             */
/*   Updated: 2023/11/15 17:43:26 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <fcntl.h>

# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>


int		ft_clean_mult_allocations(char **arrays);
int		ft_exec_command(char *command, char **env);
void	ft_minishell_error(int cod_exit, char *str);

#endif