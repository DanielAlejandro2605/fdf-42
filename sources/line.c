/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:30:37 by marvin            #+#    #+#             */
/*   Updated: 2022/09/29 10:30:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_fill_one_pixel(t_img *data, double x, double y)
{
	int		offset;
	float	index;

	offset = data->offset_window;
	if ((y >= 0 && y < WIN_HEIGTH) && (x >= 0 && x < WIN_WIDTH))
	{
		index = idx(y + offset, x + offset, WIN_WIDTH) * data->bbp;
		*(int *)(data->address + (int)(index)) = 0x0000FF00;
	}
}

/* 	The Bresenham Algorithm determines the points of an n-dimensional 
	raster that should be selected to form a CLOSE APPROXIMATION to 
	draw a line between 2 points

	We can say the efficiency of this algorithm remains in the use 
	of operations (addition, subtraction, etc) of INTEGERS.

	Algorithm: 
	1. Calculate the difference between X points and Y points.

		dx -> x2 - x1
		dy -> y2 - y1
		
	2. 	Calculate the decision parameter: It's used to find the exact 
	point to draw the line. We can compute the decision parameter with 
	the following formula :

		par_decs = 2 * dy - dx

	3.	Suppose we are analyzing the point ( X(k), Y(k) )
		We can say that the next point is ( X(k + 1), Y(k + 1) )
		We find the next point depending on value of decision parameter
		(par_decs)

		We have to evaluate only two cases for change the par_decs for the 
		next point
		Above true line
		If par_decs < 0
			a.	par_decs + 1 = par_decs + 2 * dy;
				x = x + 1;
				y = y;
				
		Plotted points
		Else if par_decs >= 0
			b. 	par_decs + 1 = par_decs + (2 * dy) - (2 * dx)
				x = x + 1;
				y = y + 1; 
*/

static void	ft_bresenham(t_line *line, t_img *img)
{
	double	t;
	double	current_x;
	double	current_y;
	int		i;

	i = 0;
	while (i <= line->length)
	{
		t = (double)i / line->length;
		current_x = line->x1 + (t * (line->x2 - line->x1));
		current_y = line->y1 + (t * (line->y2 - line->y1));
		ft_fill_one_pixel(img, current_x, current_y);
		i++;
	}
}

static void	ft_draw_line(t_fdf *fdf, t_img *img, t_vec2d vec_1, t_vec2d vec_2)
{
	t_line	line;

	line.x1 = (int)vec_1.x;
	line.y1 = (int)vec_1.y;
	line.x2 = (int)vec_2.x;
	line.y2 = (int)vec_2.y;
	(void)fdf;
	line.dx = ft_abs(line.x2, line.x1);
	line.dy = ft_abs(line.y2, line.y1);
	if (line.dx > line.dy)
		line.length = line.dx;
	else
		line.length = line.dy;
	ft_bresenham(&line, img);
}

static void	ft_last_lines(t_fdf *fdf)
{
	t_vec2d	vec_bottom_left;
	t_vec2d	vec_bottom_right;
	t_vec2d	vec_top_right;
	int		last_row;
	int		last_col;

	last_row = fdf->map.map_heigth;
	last_col = fdf->map.map_width;
	vec_top_right = fdf->map.vertex[idx(0, last_col - 1, 0)];
	vec_bottom_left = fdf->map.vertex[idx(last_row, 0, last_col) - last_col];
	vec_bottom_right = fdf->map.vertex[idx(last_row, 0, last_col) - 1];
	ft_draw_line(fdf, &fdf->img, vec_top_right, vec_bottom_right);
	ft_draw_line(fdf, &fdf->img, vec_bottom_left, vec_bottom_right);
}

void	ft_draw_lines(t_fdf *fdf, t_img *img)
{
	int		row;
	int		col;

	row = 0;
	while (row < fdf->map.map_heigth - 1)
	{
		col = 0;
		while (col < (fdf->map.map_width - 1))
		{
			ft_draw_line(fdf, img, \
					fdf->map.vertex[idx(row, col, fdf->map.map_width)], \
					fdf->map.vertex[idx(row, col + 1, fdf->map.map_width)]);
			ft_draw_line(fdf, img, \
					fdf->map.vertex[idx(row, col, fdf->map.map_width)], \
					fdf->map.vertex[idx(row + 1, col, fdf->map.map_width)]);
			col++;
		}
		row++;
	}
	ft_last_lines(fdf);
}