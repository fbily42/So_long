/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:36:17 by fbily             #+#    #+#             */
/*   Updated: 2022/08/12 02:26:53 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lignes(char *file_path)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	close(fd);
	free(line);
	return (count);
}

char	**get_map(char *file_path, char **map, int nb_ligne)
{
	int		fd;
	int		i;

	i = 0;
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

void	find_p(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == 'P')
			{
				vars->map.player.x = j;
				vars->map.player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
