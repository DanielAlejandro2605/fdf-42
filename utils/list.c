/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:27:26 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/10/20 15:39:33 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = ft_strdup((char *)content);
	new_element->next = NULL;
	return (new_element);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_lst;

	if (new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp_lst = ft_lstlast(*lst);
			temp_lst->next = new;
		}
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_free_list(t_list *lst)
{
	t_list	*aux_lst;

	while (lst)
	{
		aux_lst = lst;
		lst = lst->next;
		free(aux_lst->content);
		free(aux_lst);
	}
	lst = NULL;
	return (1);
}
