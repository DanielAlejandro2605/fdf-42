/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:40:22 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/10/20 15:46:42 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_display_usage(void)
{
	ft_printf("FDF - Usage\n");
	ft_printf("For rotation in X axis, you can use left and rigth arrow key\n");
	ft_printf("For rotation in Y axis, you can use up and down arrow key\n");
	ft_printf("For zoom in (i) and zoom out (o)\n");
	ft_printf("For quit, you can use 'Q' or 'ESC key'\n");
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		ft_printf("Incorrect usage!\n");
	if (ft_create_map_from_file(argv[1], &(fdf.map)))
		return (ft_error_message());
	ft_display_usage();
	if (ft_initialize_env(&fdf))
		return (ft_error_message());
	ft_render(&fdf);
	ft_control_hooks(&fdf);
	mlx_loop(fdf.mlx);
}
