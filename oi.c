/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evportel <evportel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:25:07 by evportel          #+#    #+#             */
/*   Updated: 2023/11/14 23:34:28 by evportel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **env __attribute__((unused)))
{
	char	*cmd = "ls";
	char	*path = "/usr/bin/ls";

	char	*cmd_args[] = {cmd, NULL};

	execve(path, cmd_args, env);
	return 1;
}
