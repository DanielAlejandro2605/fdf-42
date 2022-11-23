/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:40:22 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/23 11:31:30 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_display_usage(void)
{
	ft_printf("FDF - Usage\n");
	ft_printf("[ Rotation] -> Use left and right arrows keys.\n");
	ft_printf("[ Hide - Show] -> Use up and down arrow keys.\n");
	ft_printf("[ Zoom in - Zoom out] -> Use 'i' and 'o' keys.\n");
	ft_printf("[ Quit ] -> Use 'q' or 'ESC' keys.\n");
}

static void	ft_display_correct_usage(void)
{
	ft_printf("Incorrect usage of the program\n");
	ft_printf("Correct usage: \n");
	ft_printf("[./fdf] [map-file]\n");
}

static int	ft_little_check(char *map_name)
{
	int	last_index;

	last_index = ft_strlen_int(map_name) - 1;
	if (map_name[last_index] == '/')
	{
		ft_printf("You probably aren't launching the program ");
		ft_printf("with a file\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		ft_display_correct_usage();
	else if (!ft_little_check(argv[1]))
		return (1);
	if (ft_create_map_from_file(argv[1], &(fdf.map)))
		return (ft_error_message());
	ft_display_usage();
	if (ft_initialize_env(&fdf))
		return (ft_error_message());
	ft_render(&fdf);
	ft_control_hooks(&fdf);
	mlx_loop(fdf.mlx);
}
