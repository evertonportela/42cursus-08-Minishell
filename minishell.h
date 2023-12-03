/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:25:08 by evportel          #+#    #+#             */
/*   Updated: 2023/12/02 21:01:54 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_token
{
	char			*content;
	struct s_token	*next;
}					t_token;

typedef struct s_minishell
{
	t_token			*tokens;
}					t_minishell;

/* Tokenize functions */
void				ft_tokenize_and_add(t_token **head, char *command_line);
void				ft_add_token(t_token **head, char *content);
t_token				*ft_create_token(char *content);

/* Analyzer functions */
int					ft_analyzer_command(char *command_line);
int					ft_check_double_quotes(char *command_line);
int					ft_check_single_quotes(char *command_line);

/* Executions functions */
int					ft_executor_command(char **env, char *command);
int					ft_execve_command(char **env, char *command);
char				*ft_find_command_path(char *command, char **env);
char				**ft_get_path_command(char **env);

/* Utils functions */
int					ft_clean_mult_allocations(char **arrays);
void				ft_minishell_error(int cod_exit, char *str);
char				*ft_get_local_user(char **env);
t_minishell			*ft_minishell_init(char **env);

#endif