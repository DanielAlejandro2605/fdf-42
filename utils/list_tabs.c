/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:57:49 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/10/10 10:57:49 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

t_lstb	*ft_lstnew_tab(char *str, char sep)
{
	t_lstb	*new_element;

	new_element = (t_lstb *)malloc(sizeof(t_lstb));
	if (!new_element)
		return (NULL);
	new_element->tab = ft_split(str, sep);
	new_element->next = NULL;
	return (new_element);
}

void	ft_lstadd_back_tab(t_lstb **lst, t_lstb *new)
{
	t_lstb	*temp_lst;

	if (new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp_lst = ft_lstlast_tab(*lst);
			temp_lst->next = new;
		}
	}
}

t_lstb	*ft_lstlast_tab(t_lstb *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_free_list_tab(t_lstb *lst)
{
	t_lstb	*aux_lst;
	int		i;

	while (lst)
	{
		aux_lst = lst;
		lst = lst->next;
		i = 0;
		while (aux_lst->tab[i])
		{
			free (aux_lst->tab[i]);
			i++;
		}
		free (aux_lst->tab);
		free(aux_lst);
	}
	return (1);
}
