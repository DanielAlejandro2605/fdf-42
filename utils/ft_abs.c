/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:30:00 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/10/20 15:38:01 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_abs(int a, int b)
{
	if (a == b)
		return (0);
	else if (a < b)
		return (b - a);
	else
		return (a - b);
}
