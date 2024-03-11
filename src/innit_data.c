/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:17:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/11 00:22:12 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	data = (t_data *)malloc(sizeof(t_data));
	if(data == NULL)
		return ; // return propely with function!!
	data->envp = set_env(envp);
}

