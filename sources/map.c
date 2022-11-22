/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:44:13 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/22 13:02:48 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vertex	ft_get_vector(int x_ax_val, int y_ax_val, char *z_ax_val)
{
	t_vertex	nex_vertex;

	nex_vertex.x = (double)x_ax_val;
	nex_vertex.y = (double)y_ax_val;
	nex_vertex.z = (double)ft_atoi((char *)z_ax_val);
	nex_vertex.initial_z = nex_vertex.z;
	return (nex_vertex);
}

static int	ft_get_coords(t_lstb *list_lines_map, t_map *map)
{
	t_lstb		*aux;
	int			row;
	int			col;
	int			aux_row;

	aux = list_lines_map;
	aux_row = 0;
	row = 0;
	while (row < map->map_heigth)
	{
		col = 0;
		while (col < map->map_width)
		{
			map->coords[aux_row + col] = ft_get_vector(col, row, aux->tab[col]);
			col++;
		}
		aux_row += map->map_width;
		aux = aux->next;
		row++;
	}
	ft_free_list_tab(list_lines_map);
	return (0);
}

static void	ft_get_limits(t_map *map, t_vertex *coords)
{
	int	max_z;
	int	min_z;
	int	i;

	max_z = coords[0].z;
	min_z = coords[0].z;
	i = 0;
	while (i < map->amount_vec)
	{
		if (coords[i].z > max_z)
			max_z = coords[i].z;
		if (coords[i].z < min_z)
			min_z = coords[i].z;
		i++;
	}
	map->max_z = max_z;
	map->min_z = min_z;
}

int	ft_create_map_from_file(char *file_name, t_map *map)
{
	t_lstb	*list_lines_map;

	list_lines_map = NULL;
	map->map_width = 0;
	map->map_heigth = 0;
	map->is_rectancle_map = 1;
	if (ft_read_file(file_name, &list_lines_map, map))
		return (1);
	map->amount_vec = map->map_width * map->map_heigth;
	map->coords = (t_vertex *)malloc(sizeof(t_vertex) * (map->amount_vec));
	if (!map->coords)
		return (ft_free_list_tab(list_lines_map));
	ft_get_coords(list_lines_map, map);
	ft_get_limits(map, map->coords);
	map->vertex = (t_vec2d *)malloc(sizeof(t_vertex) * (map->amount_vec));
	if (!map->vertex)
	{
		free(map->coords);
		return (1);
	}
	return (0);
}
