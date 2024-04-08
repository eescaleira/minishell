/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:41:46 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/28 17:47:07 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
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
	char	*path_envp;
	char	**path;	/* Contains every path from path_envp separated in strings */
	int 	cmd_count;
	// t_list	*fd; //not used yet
	// int		fdout;
	// pid_t 	*pid;
	// int		cmd_count;
	// char 	**cmd;
	// char	*cmd_path;
	// int		i;
	
}				t_data;

/* main */
int main(int argc, char **argv, char **envp);

/* init data */
char	*get_path_envp(t_data *data);
t_list	*set_env(char **envp);
void	innit_struct(t_data *data, char **envp);

/* builtin functions */
int builtin_pwd(t_data *data);
int builtin_env(t_data *data);

/* command handling */
int	get_command_count(t_data *data);
void get_path(t_data *data, char *cmd);
int	get_cmd_path(t_data *data, char *cmd);// test nedded


/* list functions */
t_list	*lst_new(void *content); // void instead of char ?!
t_list	*lst_last(t_list *lst);
void	lst_add_at_end(t_list **lst, t_list *new);

/* string functions */
size_t	ft_strlen(const char *s);
int	ft_split(char ***strs, char *s, char c);
int	ft_substr(char **str, char *s, int start, int len);
int	ft_strncmp(char *s1, const char *s2, int n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif