/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:41:46 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/19 19:23:38 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "pipex/inc/pipex.h"

typedef struct s_data
{
	int		fdin;
	int		fdout;
	pid_t 	*pid;
	char	**path;
	int		cmd_count;
	char 	**cmd;
	char	*cmd_path;
	int		i;
	
}				t_data;

/* main */
int main(int argc, char **argv, char **envp);

/* info initialization */
void	get_path(t_data *data, char **envp);
void	get_cmds(t_data *data);


#endif