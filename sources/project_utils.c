/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:11:35 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/10/04 14:15:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	idx(int row, int col, int dim)
{
	return ((row * dim) + col);
}

double	ft_deg_to_rad(double angle)
{
	double	radians;

	radians = angle * (M_PI / 180);
	return (radians);
}
