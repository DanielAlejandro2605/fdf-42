/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:41:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/22 17:49:39 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	ft_get_scale(t_fdf *fdf)
{
	double	init_scale_dim;

	init_scale_dim = 0.0;
	if (fdf->map.amount_vec > 0 && fdf->map.amount_vec <= 500)
		init_scale_dim = 50;
	else if (fdf->map.amount_vec > 500 && fdf->map.amount_vec <= 1000)
		init_scale_dim = 40;
	else if (fdf->map.amount_vec > 1000 && fdf->map.amount_vec <= 2000)
		init_scale_dim = 30;
	else if (fdf->map.amount_vec > 2000 && fdf->map.amount_vec <= 3000)
		init_scale_dim = 20;
	else if (fdf->map.amount_vec > 3000 && fdf->map.amount_vec <= 4000)
		init_scale_dim = 10;
	else if (fdf->map.amount_vec > 4000 && fdf->map.amount_vec <= 5000)
		init_scale_dim = 5;
	else if (fdf->map.amount_vec > 5000 && fdf->map.amount_vec <= 10000)
		init_scale_dim = 2.5;
	else if (fdf->map.amount_vec > 10000)
		init_scale_dim = 1.5;
	return (init_scale_dim);
}

static	t_vec2d	ft_get_origins(t_fdf *fdf)
{
	t_vec2d	origin;
	double	thetha;
	double	cos_thetha;
	double	sin_thetha;
	t_vec2d	c_map;

	thetha = ft_deg_to_rad(fdf->cam.angle_iso_projection);
	cos_thetha = cos(thetha);
	sin_thetha = sin(thetha);
	c_map.x = fdf->map.map_width / 2;
	c_map.y = fdf->map.map_heigth / 2;
	origin.x = (c_map.x - c_map.y) * cos_thetha;
	origin.y = ((c_map.x + c_map.y + 1) * sin_thetha - 1);
	return (origin);
}

static int	ft_init_img(t_fdf *fdf)
{
	t_img	*img;

	img = &fdf->img;
	img->img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGTH);
	if (img->img == NULL)
		return (1);
	img->address = mlx_get_data_addr(img->img, &img->bbp, \
									&img->line_length, &img->endian);
	img->offset_window = 0;
	img->bbp /= 8;
	return (0);
}

/*
According to the content of the link: 
http://www.gandraxa.com/isometric_projection.xml
This is a correct value for get the iso projection
*/

void	ft_init_cam(t_fdf *fdf)
{
	t_cam		*cam;

	cam = &fdf->cam;
	cam->scale = ft_get_scale(fdf);
	cam->angle_iso_projection = 26.565;
	cam->angle_y_rot = 0;
	cam->cen_screen_x = WIN_WIDTH / 2;
	cam->cen_screen_y = WIN_HEIGTH / 2;
	cam->origins = ft_get_origins(fdf);
}

int	ft_initialize_env(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		return (1);
	fdf->window = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGTH, "FdF");
	if (fdf->window == NULL)
		ft_error_exit(fdf);
	if (ft_init_img(fdf))
		ft_error_exit(fdf);
	ft_init_cam(fdf);
	return (0);
}
