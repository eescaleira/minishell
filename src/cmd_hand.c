/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_hand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:17:15 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/11 18:36:02 by eescalei         ###   ########.fr       */
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

int builtin_pwd(t_data *data) // not tested
{
	t_list	*temp;
	temp = data->envp;
	while(temp != NULL)
	{
		if(ft_strncmp(temp->content, "PWD=", 4) == 0)
		{
			// print string after PWD=
			// Prototype: 
			//			ft_putstr_fd(temp->content + 4, 1);
			//			ft_putstr_fd("\n", 1);

			return (0);
		}
		temp = temp->next;
	}
	retun(-1);
	// find fd to where string will be written
	// learn how to use errno to check if string allocated is enough(if you decide to use getcwd!! )
}