/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:25:08 by evportel          #+#    #+#             */
/*   Updated: 2023/11/15 19:01:25 by evportel         ###   ########.fr       */
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

/* Executions functions */
int		ft_exec_command(char *command, char **env);
char	*ft_find_command_path(char *command, char **env);
char	**ft_get_path_command(char **env);

/* Utils functions */
int		ft_clean_mult_allocations(char **arrays);
void	ft_minishell_error(int cod_exit, char *str);
char	*ft_get_local_user(char **env);

#endif