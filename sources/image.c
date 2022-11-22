/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:38:32 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/22 12:27:58 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_clear_img(t_img *img)
{
	ft_bzero(img->address, WIN_WIDTH * WIN_HEIGTH * img->bbp);
}

static void	ft_position_verts_to_screen(t_fdf *fdf)
{
	int		row;
	int		col;
	int		aux_row;
	int		index;

	aux_row = 0;
	row = 0;
	while (row < fdf->map.map_heigth)
	{
		col = 0;
		while (col < fdf->map.map_width)
		{
			index = aux_row + col;
			fdf->map.vertex[index] = ft_position_point(fdf, \
									&fdf->map.coords[index]);
			col++;
		}
		aux_row += fdf->map.map_width;
		row++;
	}
}

void	ft_render(t_fdf *fdf)
{
	ft_clear_img(&fdf->img);
	ft_position_verts_to_screen(fdf);
	ft_draw_lines(fdf, &fdf->img);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img.img, 0, 0);
}
