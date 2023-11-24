/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:25:08 by evportel          #+#    #+#             */
/*   Updated: 2023/11/23 21:54:20 by evportel         ###   ########.fr       */
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
# include <errno.h>

/* Analyzer functions */
int		ft_analyzer_command(char *command_line);
int		ft_check_double_quotes(char *command_line);
int		ft_check_single_quotes(char *command_line);

/* Executions functions */
int		ft_executor_command(char **env, char *command);
int		ft_execve_command(char **env, char *command);
char	*ft_find_command_path(char *command, char **env);
char	**ft_get_path_command(char **env);

/* Utils functions */
int		ft_clean_mult_allocations(char **arrays);
void	ft_minishell_error(int cod_exit, char *str);
char	*ft_get_local_user(char **env);

#endif