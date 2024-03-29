/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:20:45 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/11 18:30:44 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_count_word(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

int	ft_size_word(char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
	return ;
}

int	ft_split(char ***strs, char *s, char c)
{
	int		i;
	int		word;
	int		size;
	int		j;

	i = 0;
	j = 0;
	size = 0;
	word = ft_count_word(s, c);
	*strs = (char **)malloc((word + 1) * sizeof(char *));
	while (j < word)
	{
		while (s[i] == c && s[i])
			i++;
		size = ft_size_word(s, c, i);
		strs[0][j] = (char *)malloc((size + 1) * sizeof(char));
		ft_substr(&(strs[0][j]), s, i, size);
		if (!strs[0][j])
			ft_free(*strs, j);
		i += size;
		j++;
	}
	strs[0][j] = NULL;
	return (0);
}
