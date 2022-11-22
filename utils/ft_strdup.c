/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:03:06 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/05/06 20:40:51 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen_int((char *)s);
	dup = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
