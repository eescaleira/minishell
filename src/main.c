/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 09:34:20 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/25 13:51:57 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_data	data;
	innit_struct(&data, envp);
	get_cmd_path(&data, "lfg -l");
	// char *cmd = data.cmd->content->cmd_path;
	// printf("PATH: %s\n", (char *)data.cmd->content);
	// free(data);
	return (0);
}
