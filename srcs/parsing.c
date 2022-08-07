/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:50:21 by fbily             #+#    #+#             */
/*   Updated: 2022/08/07 16:16:32 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parsing(char *argv)
{
	char	**map;
	char	*pts;
	int		fd;
	int		i;

	i = 0;
	map = NULL;
	pts = ft_strrchr(argv, '.');
	if (pts == NULL || ft_strncmp(pts, ".ber", 5) != 0 || *pts == *argv)
		return (1);
	fd = open(argv, __O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), 1);
	map = get_map(argv, map);
	while (map[i])
		ft_printf("%s", map[i++]);
	clean_map(map);
	return (0);
}

int	count_lignes(char *file_path)
{
	char	buf[1];
	int		fd;
	int		count;
	int		readed;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		readed = read(fd, buf, 1);
		if (buf[0] == '\n')
			count++;
		if (readed == 0)
			break ;
	}
	close(fd);
	return (count);
}

char	**get_map(char *file_path, char **map)
{
	int		nb_ligne;
	int		fd;
	int		i;

	i = 0;
	nb_ligne = count_lignes(file_path);
	fd = open(file_path, O_RDONLY);
	map = malloc(sizeof(char *) * (nb_ligne + 1));
	if (map == NULL || fd == -1)
		return (NULL);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	close (fd);
	return (map);
}

void	clean_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
