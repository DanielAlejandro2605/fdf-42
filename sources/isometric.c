/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:34:36 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/09/08 18:34:36 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vertex	ft_get_x_point(t_fdf *fdf, t_vertex *coordinates_2d)
{
	t_vertex	rot_point;
	double		thetha;
	double		x_point;
	double		y_point;

	thetha = ft_deg_to_rad(fdf->cam.angle_y_rot);
	x_point = (coordinates_2d->x) - (fdf->map.map_width / 2);
	y_point = (coordinates_2d->y) - (fdf->map.map_heigth / 2);
	rot_point.x = (x_point * cos(thetha)) - (y_point * sin(thetha));
	rot_point.y = (x_point * sin(thetha)) + (y_point * cos(thetha));
	rot_point.z = coordinates_2d->z;
	return (rot_point);
}

/*Function that return the isometric representation of 3D coordinates
for then make the translation, scaling and rotation operations*/
static t_vec2d	ft_get_iso_point(t_fdf *fdf, t_vertex *coord)
{
	t_vec2d		point_iso;
	double		thetha;
	double		cos_t;
	double		sin_t;

	thetha = ft_deg_to_rad(fdf->cam.angle_iso_projection);
	cos_t = cos(thetha);
	sin_t = sin(thetha);
	point_iso.x = (coord->x - coord->y) * cos_t * fdf->cam.scale \
						- fdf->cam.origins.x + fdf->cam.cen_screen_x;
	point_iso.y = ((coord->x + coord->y) * sin_t - coord->z) * fdf->cam.scale \
						- fdf->cam.origins.y + fdf->cam.cen_screen_y;
	return (point_iso);
}

t_vec2d	ft_position_point(t_fdf *fdf, t_vertex *coordinates_2d)
{
	t_vertex	vector_x;
	t_vec2d		point_iso;

	vector_x = ft_get_x_point(fdf, coordinates_2d);
	point_iso = ft_get_iso_point(fdf, &vector_x);
	return (point_iso);
}
