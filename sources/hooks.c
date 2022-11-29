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

static void	ft_limit_initial_z(t_vertex *vec, int scale_direction)
{
	double	vec_z_value;
	double	initial_z_value;

	vec_z_value = vec->z;
	initial_z_value = vec->initial_z;
	if (scale_direction == 0)
	{
		if (ft_isnegative(vec_z_value) && vec_z_value < -1)
			vec->z += 1;
		else if (!ft_isnegative(vec_z_value) && vec_z_value > 1)
			vec->z -= 1;
	}
	else if (scale_direction == 1)
	{
		if (ft_isnegative(vec_z_value) && vec_z_value > initial_z_value)
			vec->z -= 1;
		else if (!ft_isnegative(vec_z_value) && vec_z_value < initial_z_value)
			vec->z += 1;
	}
}

static void	ft_scale_vertex(t_fdf *fdf, int scale_direction)
{
	int		i;
	double	vec_z_value;

	i = 0;
	vec_z_value = 0;
	while (i < fdf->map.amount_vec)
	{
		vec_z_value = fdf->map.coords[i].initial_z;
		if (vec_z_value != 0)
		{
			ft_limit_initial_z(&fdf->map.coords[i], scale_direction);
		}
		i++;
	}
}

static int	key_hook(int key_code, t_fdf *fdf)
{
	ft_printf("key code : %d\n", key_code);
	if (key_code == ROTATE_LEFT)
		fdf->cam.angle_y_rot -= 5;
	else if (key_code == ROTATE_RIGTH)
		fdf->cam.angle_y_rot += 5;
	else if (key_code == ROTATE_UP)
		ft_scale_vertex(fdf, 1);
	else if (key_code == ROTATE_DOWN)
		ft_scale_vertex(fdf, 0);
	else if (key_code == ZOOM_IN)
		fdf->cam.scale += 2;
	else if (key_code == ZOOM_OUT)
		fdf->cam.scale -= 2;
	else if (key_code == W_OFFSET)
		fdf->img.offset_window_y -= 10;
	else if (key_code == S_OFFSET)
		fdf->img.offset_window_y += 10;
	else if (key_code == A_OFFSET)
		fdf->img.offset_window_x -= 10;
	else if (key_code == D_OFFSET)
		fdf->img.offset_window_x += 10;
	else if (key_code == ESCAPE)
		ft_safe_exit_free(fdf);
	ft_render(fdf);
	return (0);
}

void	ft_control_hooks(t_fdf *fdf)
{
	mlx_key_hook(fdf->window, &key_hook, fdf);
	mlx_hook(fdf->window, 17, KeyPressMask, &ft_safe_window_free, fdf);
}
