/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_hand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:17:15 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/28 15:42:42 by eescalei         ###   ########.fr       */
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
		if(ft_strncmp(temp->content, "PATH=", 5) == 0)
		{
			ft_split(&(data->path), temp->content + 5, ':');
			break ;
		}
	if(data->path == NULL)
	{
		printf("Erro: nao foi possivel encontrar PATH!"); // change to ft_printf
		//free everything
		exit(1);
	}
}

int	get_cmd_path(t_data *data, char *cmd)// cmd_path transformar em estrutura de comando
{
	int		i;
	char	*path;
	char	*cmd_path;
	char	**args;

	i = 0;
	ft_split(&args, cmd, ' ');	//free args
	while (data->path[i] != NULL)
	{
		path = ft_strjoin(data->path[i], "/");
		cmd_path = ft_strjoin(path, args[0]);
		if (access(cmd_path, X_OK) == 0)
		{	
			lst_add_at_end(&data->cmd, lst_new(cmd_path));
			printf("Command PATH: %s\n", cmd_path);
			free(path);
			return (0);
		}
		free(path);
		free(cmd_path);
		i++;
	}
	printf("Command not found\n");
	return (-1);
}
