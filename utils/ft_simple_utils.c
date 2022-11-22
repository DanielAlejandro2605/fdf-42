/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:05:17 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/07/17 18:23:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nbr)
{
	int			i;
	long int	number;

	i = 0;
	number = (long int)nbr;
	if (nbr < 0)
	{
		number = number * -1;
		i += ft_putchar('-');
	}
	if (number > 9)
	{
		i += ft_putnbr(number / 10);
		i += ft_putnbr(number % 10);
	}
	else
	{
		i += ft_putchar(number + '0');
	}
	return (i);
}

int	ft_puthex(unsigned int hex, char format)
{
	int	i;

	i = 0;
	if (hex >= 16)
	{
		i += ft_puthex(hex / 16, format);
		i += ft_puthex(hex % 16, format);
	}
	else
	{
		if (hex <= 9)
			i += ft_putchar(hex + '0');
		else
		{
			if (format == 'x')
				i += ft_putchar((hex - 10) + 'a');
			else if (format == 'X')
				i += ft_putchar((hex - 10) + 'A');
		}
	}
	return (i);
}
