/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:41:46 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/11 00:02:30 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
#include <string.h>
# include <ctype.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_list
{
	struct s_list	*prev;
	char			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	t_list	*envp;	/* list of environment variables */
	t_list	*vars;	/* list of variables defined by user */
	// int		fdin;
	// int		fdout;
	// pid_t 	*pid;
	// char	**path;
	// int		cmd_count;
	// char 	**cmd;
	// char	*cmd_path;
	// int		i;
	
}				t_data;

/* main */
int main(int argc, char **argv, char **envp);

/* init data */
t_list	*set_env(char **envp);
void	innit_struct(t_data *data, char **envp);

/* list functions */
t_list	*lst_new(char *content);
t_list	*lst_last(t_list *lst);
void	lst_add_at_end(t_list **lst, t_list *new);

#endif