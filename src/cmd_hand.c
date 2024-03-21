/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_hand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:17:15 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/21 11:21:39 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_command_count(t_data *data) // not tested
{
	t_list	*temp;
	
	if(!(data->cmd))/* if linked list for command storage don't exit */
		return (-1);
	temp = data->cmd;
	data->cmd_count = 0;
	while(temp != NULL)
	{
		data->cmd_count++;
		temp = temp->next;
	}
	return (data->cmd_count);
}

void get_path(t_data *data, char *cmd)
{
	t_list	*temp;
	int	i;

	i = 0;
	temp = data->env;
	while(temp != NULL)
	{
		if(ft_strncmp(temp->content, "PATH=", 5) == 0)
		{
			ft_splitt(&(data->path), temp->content + 5, ':');
			break ;
		}
		
	}
	if(data->path == NULL)
	{
		printf("Erro: nao foi possivel encontrar PATH!"); // change to ft_printf
		//free everything
		exit(1);
	}
}

void	get_cmds(t_data *data)// correct this function (adapt to new struct)
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