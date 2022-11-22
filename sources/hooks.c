/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:52:00 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/10/16 14:52:00 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_limit_initial_z(t_vertex *vec)
{
	if (vec->z <= 0)
		vec->z = 1;
	else if(vec->z >= vec->initial_z)
		vec->z = vec->initial_z;
	// else if (fdf->map.coords[i].z >= fdf->map.max_z)
	// 			fdf->map.coords[i].z = fdf->map.max_z;
}

static void	ft_scale_altitude(t_fdf *fdf, int scale_direction)
{
	int	i;

	i = 0;
	while (i < fdf->map.amount_vec)
	{
		if (fdf->map.coords[i].z != 0)
		{
			if (scale_direction == 0)
				fdf->map.coords[i].z -= 1;
			else if (scale_direction == 1)
				fdf->map.coords[i].z += 1;
			ft_limit_initial_z(&fdf->map.coords[i]);
		}
		i++;
	}
	printf("max - z%d min -z%d\n", fdf->map.max_z, fdf->map.min_z);
}

static void	ft_limit_angle_iso(double *angle_iso)
{
	if (*angle_iso <= 0.0)
	{
		*angle_iso = 0.0;
	}
	else if (*angle_iso >= 50.0)
	{
		*angle_iso = 50.0;
	}
}

static int	key_hook(int key_code, t_fdf *fdf)
{
	if (key_code == ROTATE_LEFT)
		fdf->cam.angle_y_rot -= 5;
	else if (key_code == ROTATE_RIGTH)
		fdf->cam.angle_y_rot += 5;
	else if (key_code == ROTATE_UP)
		ft_scale_altitude(fdf, 1);
	else if (key_code == ROTATE_DOWN)
		ft_scale_altitude(fdf, 0);
	else if (key_code == ZOOM_IN)
		fdf->cam.scale += 2;
	else if (key_code == ZOOM_OUT)
		fdf->cam.scale -= 2;
	else if (key_code == ESCAPE)
		ft_safe_exit_free(fdf);
	ft_limit_angle_iso(&fdf->cam.angle_iso_projection);
	ft_render(fdf);
	return (0);
}

void	ft_control_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->window, &key_hook, fdf);
	mlx_hook(fdf->window, 17, KeyPressMask, &ft_safe_window_free, fdf);
}
