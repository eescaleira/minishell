/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:17:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/25 13:49:13 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_path_envp(t_data *data)
{
	t_list *temp;

	temp = data->env;
	while(temp != NULL)
	{
		if (ft_strncmp(temp->content, "PATH=", 5) == 0)
		{
			data->path_envp = (char *)malloc((ft_strlen(temp->content) - 5 + 1) * sizeof(char));
			ft_substr(&data->path_envp, temp->content, 5, ft_strlen(temp->content) - 5);
			return (data->path_envp);
		}
		temp = temp->next;
	
	}
	return (NULL); /* if PATH is not found */
}

t_list	*set_env(char **envp)
{
	t_list *env;
	t_list *temp;
	env = lst_new(*envp);
	temp = env;
	while(*++envp != NULL)
		lst_add_at_end(&env, lst_new(*envp));
	env = temp;
	return (env);
}


void	innit_struct(t_data *data, char **envp)
{
	data->env = set_env(envp);
	data->path_envp = get_path_envp(data);
	ft_split(&data->path, data->path_envp, ':');
}

