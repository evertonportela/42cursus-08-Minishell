/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:23:20 by evportel          #+#    #+#             */
/*   Updated: 2023/11/20 23:20:23 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_get_path_command(char **env)
{
	int		index;
	char	**env_all_path;
	char	*env_temp;

	index = 0;
	while (env[index] && ft_strncmp(env[index], "PATH=", 5))
		index++;
	if (!env[index])
		return (NULL);
	env_temp = env[index] + 5;
	env_all_path = ft_split(env_temp, ':');
	index = 0;
	while (env_all_path[index])
	{
		env_temp = env_all_path[index];
		env_all_path[index] = ft_strjoin(env_temp, "/");
		free(env_temp);
		index++;
	}
	return (env_all_path);
}

char	*ft_find_command_path(char *command, char **env)
{
	int		index;
	char	*command_path;

	env = ft_get_path_command(env);
	index = 0;
	while (env[index])
	{
		command_path = ft_strjoin(env[index], command);
		if (access(command_path, F_OK | X_OK) == 0)
		{
			ft_clean_mult_allocations(env);
			return (command_path);
		}
		free(command_path);
		index++;
	}
	ft_clean_mult_allocations(env);
	return (NULL);
}

int	ft_exec_command(char *command, char **env)
{
	char	**command_args;
	char	*path_exec;

	command_args = ft_split(command, ' ');
	if (command_args == NULL)
		return (EXIT_FAILURE);
	path_exec = ft_find_command_path(command_args[0], env);
	if (path_exec == NULL)
	{
		free(path_exec);
		ft_clean_mult_allocations(command_args);
		return (EXIT_FAILURE);
	}
	return (execve(path_exec, command_args, env));
}
