/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:25:35 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/23 15:45:52 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <X11/X.h>
# include "../mlx_linux/mlx.h"
# include "./utils.h"

# include <stdio.h>
# define WIN_WIDTH  1200
# define WIN_HEIGTH 900

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define DEFAULT_COLOR 0x0000FF00
# define COLOR 0x860c0c
 
# define ROTATE_LEFT 65361
# define ROTATE_RIGTH 65363
# define ROTATE_UP 65362
# define ROTATE_DOWN 65364
# define ZOOM_IN 105
# define ZOOM_OUT 111
# define ESCAPE 65307

typedef struct vector_2d
{
	double	x;
	double	y;
	int		color;
}			t_vec2d;

typedef struct line
{
	int		dx;
	int		dy;
	int		length;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color_1;
	int		color_2;
}			t_line;

typedef struct s_cam
{
	double		scale;
	double		angle_iso_projection;
	double		angle_y_rot;
	double		cen_screen_x;
	double		cen_screen_y;
	t_vec2d		origins;
}				t_cam;

typedef struct image
{
	void	*img;
	char	*address;
	int		offset_window;
	int		bbp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct vector
{
	double	x;
	double	y;
	double	z;
	double	initial_z;
	int		color;
}			t_vertex;

typedef struct map
{
	int			map_width;
	int			map_heigth;
	int			amount_vec;
	int			is_rectancle_map;
	t_vertex	*coords;
	t_vec2d		*vertex;
}				t_map;

typedef struct fdf
{
	void		*mlx;
	void		*window;
	t_img		img;
	t_map		map;
	t_cam		cam;
}				t_fdf;

/*Read*/
int		ft_read_file(char *file_name, t_lstb **lst_tabs, t_map *map);
/*Map*/
int		ft_create_map_from_file(char *file_name, t_map *map);
/*Environment*/
int		ft_initialize_env(t_fdf *fdf);
/*Render*/
void	ft_render(t_fdf *fdf);
/*Lines*/
void	ft_draw_lines(t_fdf *fdf, t_img *img);
/*Hooks*/
void	ft_control_hooks(t_fdf *fdf);
/*Isometric Projection*/
t_vec2d	ft_position_point(t_fdf *fdf, t_vertex *coordinates_2d);
/*Destroy*/
int		ft_safe_window_free(t_fdf *fdf);
void	ft_safe_exit_free(t_fdf *fdf);
void	ft_error_exit(t_fdf *fdf);
int		ft_error_message(void);
/*Isometric Utils*/
double	ft_deg_to_rad(double angle);
int		idx(int row, int col, int dim);
#endif