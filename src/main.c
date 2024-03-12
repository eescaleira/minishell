/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:34:20 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/12 00:33:20 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_data	data;
	innit_struct(&data, envp);
	
	// free(data);
	return (0);
}
