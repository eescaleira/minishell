/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:59:07 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/19 19:27:04 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int execute_echo(char **args, int fd); // char[0] - echo, char[1] - -n, char[2] - string
