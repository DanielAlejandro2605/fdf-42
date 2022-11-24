/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:33:46 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/10/11 10:33:46 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_get_lines_from_file(char *file_name, t_list **lst)
{
	int		fd_map;
	char	*line;
	t_list	*aux;
	char	c;

	fd_map = open(file_name, O_RDONLY);
	if (fd_map == -1)
		return (1);
	line = get_next_line(fd_map);
	while (line)
	{
		aux = ft_lstnew((void *)line);
		if (!aux)
		{
			free(line);
			return (1);
		}
		ft_lstadd_back(lst, aux);
		free(line);
		line = get_next_line(fd_map);
		if (!line && read(fd_map, &c, sizeof(char)) > 0)
			return (ft_free_list(*lst));
	}
	close(fd_map);
	return (0);
}

static int	ft_number_words_in_line(char *str, char sep)
{
	int		i;
	int		number_words;

	number_words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
		{
			number_words++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (number_words);
}

/*Setting map->is_rectancle_map*/
static int	ft_get_dimensions_map(t_list *lst, t_map *map)
{
	char	*line;
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		line = (char *)aux->content;
		if (map->map_width == 0)
			map->map_width = ft_number_words_in_line(line, ' ');
		else if (map->map_width != ft_number_words_in_line(line, ' '))
			map->is_rectancle_map = 0;
		map->map_heigth++;
		aux = aux->next;
	}
	ft_free_list(lst);
	return (0);
}

int	ft_read_file(char *file_name, t_lstb **lst_tabs, t_map *map)
{
	t_lstb		*aux_tabs;
	t_list		*lines_map;
	t_list		*aux_lines;

	lines_map = NULL;
	if (ft_get_lines_from_file(file_name, &lines_map))
		return (1);
	aux_lines = lines_map;
	while (aux_lines)
	{
		aux_tabs = ft_lstnew_tab((char *)aux_lines->content, ' ');
		if (!aux_tabs)
		{
			ft_free_list(lines_map);
			if (lst_tabs)
				ft_free_list_tab(*lst_tabs);
			return (1);
		}
		ft_lstadd_back_tab(lst_tabs, aux_tabs);
		aux_lines = aux_lines->next;
	}
	ft_get_dimensions_map(lines_map, map);
	return (0);
}
