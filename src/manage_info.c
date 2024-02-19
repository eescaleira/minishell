/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:07:16 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/19 19:22:56 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_path(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ft_splitt(&(data->path), envp[i] + 5, ':');
			break ;
		}
		i++;
	}
}

void	get_cmds(t_data *data)
{
	int		i;
	char	*path;
	char	*cmd_path;

	i = 0;
	data->cmd_path = NULL;
	while (data->path[i] != NULL)
	{
		path = ft_strjoin(data->path[i], "/");
		cmd_path = ft_strjoin(path, data->cmd[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			data->cmd_path = cmd_path;
			free(path);
			return ;
		}
		free(path);
		free(cmd_path);
		i++;
	}
}
