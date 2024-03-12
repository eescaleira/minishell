/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_hand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:17:15 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/12 00:17:38 by eescalei         ###   ########.fr       */
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
