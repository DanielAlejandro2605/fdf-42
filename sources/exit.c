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

int	ft_error_message(void)
{
	ft_printf("Something went wrong. ");
	ft_printf("This can be caused by :\n");
	ft_printf(" - Found wrong line length.\n");
	ft_printf(" - No data found in the file.\n");
	ft_printf(" - No permissions file.\n");
	ft_printf(" - Or a failed malloc.\n");
	return (1);
}

int	ft_safe_window_free(t_fdf *fdf)
{
	ft_safe_exit_free(fdf);
	return (0);
}

void	ft_safe_exit_free(t_fdf *fdf)
{
	free(fdf->map.vertex);
	free(fdf->map.coords);
	mlx_clear_window(fdf->mlx, fdf->window);
	mlx_destroy_image(fdf->mlx, fdf->img.img);
	mlx_destroy_window(fdf->mlx, fdf->window);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit(1);
}

void	ft_error_exit(t_fdf *fdf)
{
	free(fdf->map.vertex);
	free(fdf->map.coords);
	if (fdf->window)
		mlx_destroy_window(fdf->mlx, fdf->window);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	ft_error_message();
	exit(1);
}
