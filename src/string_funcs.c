/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:30:19 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/25 13:31:44 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (*(s + x) != '\0')
		x++;
	return (x);
}


int	ft_substr(char **str, char *s, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		(*str)[i] = s[start + i];
		i++;
	}
	(*str)[i] = '\0';
	return (0);
}

int	ft_strncmp(char *s1, const char *s2, int n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n < 0)
		return (-1);
	while (n > 0 && *str1 == *str2 && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*str1 - *str2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		i;

	i = 0;
	ns = malloc((ft_strlen(s1) + ft_strlen(s2) +1) * sizeof(char));
	if (ns == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ns[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		ns[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
