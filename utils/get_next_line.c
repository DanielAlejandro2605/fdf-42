/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:58:04 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/10/20 15:39:11 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

// char	*get_next_line(int fd)
// {
// 	static char	*buffer_static;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
// 		return (NULL);
// 	// buffer_static = ft_read_file(fd, buffer_static);
// 	buffer_static = NULL;
// 	if (!buffer_static)
// 		return (NULL);
// 	line = ft_get_line(buffer_static);
// 	buffer_static = ft_advance_buffer(buffer_static);
// 	return (line);
// }

// char	*ft_read_file(int fd, char *response_static)
// {
// 	int		num_bytes_read;
// 	char	*buffer_file;

// 	buffer_file = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!buffer_file)
// 		return (NULL);
// 	num_bytes_read = 1;
// 	while (num_bytes_read > 0)
// 	{
// 		num_bytes_read = read(fd, buffer_file, BUFFER_SIZE);
// 		if (num_bytes_read == -1)
// 		{
// 			free(buffer_file);
// 			return (NULL);
// 		}
// 		buffer_file[num_bytes_read] = 0;
// 		response_static = ft_concatenation(response_static, buffer_file);
// 		if (ft_strchr(buffer_file, '\n'))
// 			break ;
// 	}
// 	free(buffer_file);
// 	return (response_static);
// }

// char	*ft_get_line(char *buffer)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	if (!buffer[i])
// 		return (NULL);
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	line = ft_calloc(i + 2, sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i] && buffer[i] == '\n')
// 		line[i++] = '\n';
// 	line[i] = '\0';
// 	return (line);
// }

// char	*ft_concatenation(char *res_buff_static, char *buff_file)
// {
// 	char	*temp_concatenation;

// 	temp_concatenation = ft_strjoin_secure(res_buff_static, buff_file);
// 	free(res_buff_static);
// 	return (temp_concatenation);
// }

// char	*ft_advance_buffer(char *buff)
// {
// 	int		i;
// 	int		j;
// 	char	*next_line;

// 	i = 0;
// 	while (buff[i] && buff[i] != '\n')
// 		i++;
// 	if (buff[i] == '\0')
// 	{
// 		free(buff);
// 		return (NULL);
// 	}
// 	next_line = ft_calloc((ft_strlen_int(buff) - i + 1), sizeof(char));
// 	if (!next_line)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (buff[i])
// 		next_line[j++] = buff[i++];
// 	free(buff);
// 	return (next_line);
// }

static char	*ft_concatenation(char *buffer_aux, char *buffer_file)
{
	char	*res;

	res = ft_strjoin_secure(buffer_aux, buffer_file);
	free(buffer_aux);
	return (res);
}

static void	ft_get_next_line(char *buffer_aux, char buffer_static[])
{
	int		i;
	int		j;

	i = 0;
	while (buffer_aux[i] && buffer_aux[i] != '\n')
		i++;
	if (buffer_aux[i] == '\0')
	{
		free(buffer_aux);
		return ;
	}
	i++;
	j = 0;
	while (buffer_aux[i])
		buffer_static[j++] = buffer_aux[i++];
	buffer_static[j] = '\0';
	free(buffer_aux);
}

static char	*ft_read_file(int fd, char buffer_static[], char *buffer_aux)
{
	int		num_bytes_read;
	char	*buffer_file;

	buffer_file = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer_file)
		return (NULL);
	buffer_aux = ft_concatenation(buffer_aux, buffer_static);
	ft_bzero(buffer_static, BUFFER_SIZE + 1);
	num_bytes_read = 1;
	while (num_bytes_read > 0)
	{
		num_bytes_read = read(fd, buffer_file, BUFFER_SIZE);
		if (num_bytes_read == -1)
		{
			free (buffer_file);
			break ;
		}
		buffer_file[num_bytes_read] = 0;
		buffer_aux = ft_concatenation(buffer_aux, buffer_file);
		if (ft_strchr(buffer_file, '\n'))
			break ;
	}
	free (buffer_file);
	return (buffer_aux);
}

static char	*ft_get_line(char *buffer_aux)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer_aux[i])
		return (NULL);
	while (buffer_aux[i] && buffer_aux[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer_aux[i] && buffer_aux[i] != '\n')
	{
		line[i] = buffer_aux[i];
		i++;
	}
	if (buffer_aux[i] && buffer_aux[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer_static[BUFFER_SIZE + 1];
	char		*buffer_aux;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer_aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer_aux)
		return (NULL);
	buffer_aux = ft_read_file(fd, buffer_static, buffer_aux);
	line = ft_get_line(buffer_aux);
	ft_get_next_line(buffer_aux, buffer_static);
	return (line);
}
