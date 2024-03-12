/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:41:46 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/12 00:24:51 by eescalei         ###   ########.fr       */
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
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_data
{
	t_list	*env;	/* list of environment variables */
	t_list	*vars;	/* list of variables defined by user */
	t_list	*pipe;
	t_list 	*cmd;
	// t_list	*fd; //not used yet
	int 	cmd_count;
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

/* builtin functions */
int builtin_pwd(t_data *data);
int builtin_env(t_data *data);

/* command handling */
int	get_command_count(t_data *data);


/* list functions */
t_list	*lst_new(char *content);
t_list	*lst_last(t_list *lst);
void	lst_add_at_end(t_list **lst, t_list *new);

/* string functions */
int	ft_split(char ***strs, char *s, char c);
int	ft_substr(char **str, char *s, int start, int len);
int	ft_strncmp(char *s1, const char *s2, int n);

#endif