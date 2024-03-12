/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:17:16 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/12 00:33:17 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int builtin_pwd(t_data *data) 
{
	char *buf;

	buf = getcwd(NULL, 0);
	if(buf == NULL)
		return (-1); /* could use errno to show the error ocurred */
	// printf("%s", buf);// find fd to where string will be written
	free(buf);
	return (0);
	// learn how to use errno to check if string allocated is enough(if you decide to use getcwd!! )
}

int builtin_env(t_data *data) 
{
	t_list *temp;

	temp = data->env;
	while (temp != NULL)
	{
		// printf("%s\n", temp->content);// find fd to where string will be written
		temp = temp->next;
	}
	return (0);
}
