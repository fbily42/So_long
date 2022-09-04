/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:50:21 by fbily             #+#    #+#             */
/*   Updated: 2022/09/04 23:06:39 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parsing(t_vars *vars, char *argv)
{
	t_map	map;
	char	*pts;
	int		fd;

	map.map = NULL;
	pts = ft_strrchr(argv, '.');
	if (pts == NULL || ft_strncmp(pts, ".ber", 5) != 0 || *pts == *argv)
		return (1);
	fd = open(argv, __O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), 1);
	map.nb_ligne = count_lignes(argv);
	if (map.nb_ligne == -1)
		return (1);
	map.map = get_map(argv, map.map, map.nb_ligne);
	if (map.map == NULL)
		return (1);
	if (parse_map(&map) != 0)
		return (clean_map(map.map), 1);
	vars->map = map;
	return (0);
}

int	parse_map(t_map *map)
{
	if (check_size(map) != 0)
		return (1);
	if (check_map(map) != 0)
		return (1);
	if (count_element(map) != 0)
		return (1);
	return (0);
}

int	count_element(t_map *map)
{
	size_t	j;
	int		i;

	i = 1;
	map->count_c = 0;
	map->count_e = 0;
	map->count_p = 0;
	while (i < (map->nb_ligne - 1))
	{
		j = 1;
		while (map->map[i] && j < map->size_line - 1)
		{
			if (map->map[i][j] == 'E')
				map->count_e += 1;
			if (map->map[i][j] == 'C')
				map->count_c += 1;
			if (map->map[i][j] == 'P')
				map->count_p += 1;
			j++;
		}
		i++;
	}
	if (map->count_c < 1 || map->count_e < 1 || map->count_p != 1)
		return (1);
	return (0);
}

int	check_map(t_map *map)
{
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (map->map[0] && map->map[map->nb_ligne - 1] && j < map->size_line)
		if (map->map[0][j] != '1' || map->map[map->nb_ligne - 1][j++] != '1')
			return (1);
	while (i < (map->nb_ligne - 1))
	{
		if (map->map[i][0] != '1' || map->map[i][map->size_line - 1] != '1')
			return (1);
		j = 1;
		while (map->map[i] && j < map->size_line - 1)
		{
			if (map->map[i][j] == '1' || map->map[i][j] == '0'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'C'
				|| map->map[i][j] == 'P')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_size(t_map *map)
{
	size_t	size;
	int		i;

	i = 0;
	map->size_line = ft_strlen(map->map[0]);
	if (map->size_line < 1)
		return (1);
	if (map->map[0][map->size_line - 1] == '\n')
		map->size_line = map->size_line - 1;
	while (map->map[i])
	{
		size = ft_strlen(map->map[i]);
		if (map->map[i][size - 1] == '\n')
			size = size - 1;
		if (size != map->size_line)
			return (1);
		i++;
	}
	return (0);
}
