/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:07:48 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/17 18:23:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_len_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*number;
	int		length_number;

	length_number = ft_len_unsigned(n);
	number = (char *)malloc(sizeof(char) * length_number + 1);
	if (!number)
		return (NULL);
	number[length_number] = '\0';
	while (n != 0)
	{
		number[length_number - 1] = (n % 10) + '0';
		n /= 10;
		length_number--;
	}
	return (number);
}

int	ft_put_unsigned(unsigned int n)
{
	int		i;
	char	*number_str;

	i = 0;
	if (n == 0)
	{
		i += ft_putchar('0');
		return (i);
	}
	number_str = ft_uitoa(n);
	if (!number_str)
		return (i);
	i += ft_putstr(number_str);
	free(number_str);
	return (i);
}
