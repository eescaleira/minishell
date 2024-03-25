/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 23:39:47 by eescalei          #+#    #+#             */
/*   Updated: 2024/03/25 13:47:35 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_list	*lst_new(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->prev = NULL;
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

t_list	*lst_last(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	lst_add_at_end(t_list **lst, t_list *new)
{
	t_list	*temp;

	// if (lst)
	// {
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = lst_last(*(lst));
			new->prev = temp;
			temp->next = new;
		}
	// }
	
}