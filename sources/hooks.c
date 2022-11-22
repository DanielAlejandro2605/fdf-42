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
		fdf->cam.angle_iso_projection -= 2;
	else if (key_code == ROTATE_DOWN)
		fdf->cam.angle_iso_projection += 2;
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
