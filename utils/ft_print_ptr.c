/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:09:26 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/17 18:23:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_len_ptr(unsigned long long int_pointer)
{
	int	len;

	len = 0;
	while (int_pointer != 0)
	{
		len++;
		int_pointer /= 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long int_pointer)
{
	if (int_pointer >= 16)
	{
		ft_put_ptr(int_pointer / 16);
		ft_put_ptr(int_pointer % 16);
	}
	else
	{
		if (int_pointer <= 9)
		{
			ft_putchar(int_pointer + '0');
		}
		else
			ft_putchar(int_pointer - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long int_pointer)
{
	int	i;

	i = 0;
	if (int_pointer == 0)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	else
	{
		i += ft_putstr("0x");
		ft_put_ptr(int_pointer);
		i += ft_len_ptr(int_pointer);
	}
	return (i);
}
