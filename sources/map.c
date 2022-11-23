/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:44:13 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/23 16:04:13 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_color_contains_may(char *point_str)
{
	int i;

	i = 0;
	while (point_str[i])
	{
		if (point_str[i] >= 'A' && point_str[i] <= 'Z')
			return (1);
		i++;	
	}
	return (0);
}

static int ft_point_contain_color(char *point_str)
{
    char	*color_str;
	
	color_str = ft_strchr(point_str, ',');
	if (!color_str)
		return (0);
	return (1);
}

static t_vertex	ft_vec(int x_ax_val, int y_ax_val, char *z_ax_val, int f)
{
	t_vertex	new_vertex;

	new_vertex.x = (double)x_ax_val;
	new_vertex.y = (double)y_ax_val;
	new_vertex.z = (double)ft_atoi((char *)z_ax_val);
	new_vertex.initial_z = new_vertex.z;
	if (f)
	{
		if (ft_color_contains_may(z_ax_val))
			new_vertex.color = ft_atoi_base(z_ax_val + 4, "0123456789abcdef");
		else
			new_vertex.color = ft_atoi_base(z_ax_val + 4, "0123456789ABCDEF");
	}
	else
		new_vertex.color = 0;
	// printf("color of coords : %d\n", new_vertex.color);
	return (new_vertex);
}

static int	ft_get_coords(t_lstb *list_lines_map, t_map *map)
{
	t_lstb		*aux;
	int			row;
	int			col;
	int			ax_row;

	aux = list_lines_map;
	ax_row = 0;
	row = 0;
	while (row < map->map_heigth)
	{
		col = 0;
		while (col < map->map_width)
		{
			if (ft_point_contain_color(aux->tab[col]))
				map->coords[ax_row + col] = ft_vec(col, row, aux->tab[col], 1);
			else
				map->coords[ax_row + col] = ft_vec(col, row, aux->tab[col], 0);
			col++;
		}
		ax_row += map->map_width;
		aux = aux->next;
		row++;
	}
	ft_free_list_tab(list_lines_map);
	return (0);
}

int	ft_create_map_from_file(char *file_name, t_map *map)
{
	t_lstb	*list_lines_map;

	list_lines_map = NULL;
	map->map_width = 0;
	map->map_heigth = 0;
	map->is_rectancle_map = 1;
	map->amount_vec = 0;
	if (ft_read_file(file_name, &list_lines_map, map))
		return (1);
	map->amount_vec = map->map_width * map->map_heigth;
	map->coords = (t_vertex *)malloc(sizeof(t_vertex) * (map->amount_vec));
	if (!map->coords)
		return (ft_free_list_tab(list_lines_map));
	ft_get_coords(list_lines_map, map);
	map->vertex = (t_vec2d *)malloc(sizeof(t_vertex) * (map->amount_vec));
	if (!map->vertex)
	{
		free(map->coords);
		return (1);
	}
	return (0);
}
