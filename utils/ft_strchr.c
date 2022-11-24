/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:40:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/24 16:48:47 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s != (char )c)
		{
			if (!*s)
				return (NULL);
			s++;
		}
		return ((char *)s);
	}
	return (NULL);
}
