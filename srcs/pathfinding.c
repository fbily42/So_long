/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:15:49 by fbily             #+#    #+#             */
/*   Updated: 2022/09/19 20:41:10 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_path(t_vars vars, char *argv)
{
	t_path	path;

	path.map = NULL;
	path.visited = NULL;
	path.map = get_map(argv, path.map, vars.map.nb_ligne);
	path.visited = get_map(argv, path.visited, vars.map.nb_ligne);
	path.count_c = vars.map.count_c;
	path.count_e = vars.map.count_e;
	path.nb_ligne = vars.map.nb_ligne;
	path.size_line = vars.map.size_line;
	while (path.count_c > 0)
	{
		if (is_path_for_c(&path) == 0)
			path.count_c--;
		else
			return (clean_map(path.map), clean_map(path.visited), 1);
	}
	while (path.count_e > 0)
	{
		if (is_path_for_e(&path) == 0)
			path.count_e--;
		else
			return (clean_map(path.map), clean_map(path.visited), 1);
	}
	return (clean_map(path.map), clean_map(path.visited), 0);
}

int	is_path_for_c(t_path *path)
{
	size_t	j;
	int		i;

	find_player(path);
	erase_map(&path->visited);
	i = path->start.y;
	while (i < path->nb_ligne)
	{
		j = path->start.x;
		while (j < path->size_line)
		{
			if (path->map[i][j] == 'P' && path->visited[i][j] == '0')
				if (find_path_c(path, i, j) == 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_path_c(t_path *path, int i, size_t j)
{
	t_dir	dir;

	if (is_safe(i, j, path) == 0 && path->map[i][j] != '1'
		&& path->visited[i][j] != '1')
	{
		path->visited[i][j] = '1';
		if (path->map[i][j] == 'C')
		{
			path->map[i][j] = '0';
			return (0);
		}
		dir.up = find_path_c(path, i - 1, j);
		if (dir.up == 0)
			return (0);
		dir.left = find_path_c(path, i, j - 1);
		if (dir.left == 0)
			return (0);
		dir.down = find_path_c(path, i + 1, j);
		if (dir.down == 0)
			return (0);
		dir.right = find_path_c(path, i, j + 1);
		if (dir.right == 0)
			return (0);
	}
	return (1);
}

int	is_path_for_e(t_path *path)
{
	size_t	j;
	int		i;

	find_player(path);
	erase_map(&path->visited);
	i = path->start.y;
	while (i < path->nb_ligne)
	{
		j = path->start.x;
		while (j < path->size_line)
		{
			if (path->map[i][j] == 'P' && path->visited[i][j] == '0')
				if (find_path_e(path, i, j) == 0)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_path_e(t_path *path, int i, size_t j)
{
	t_dir	dir;

	if (is_safe(i, j, path) == 0 && path->map[i][j] != '1'
		&& path->visited[i][j] != '1')
	{
		path->visited[i][j] = '1';
		if (path->map[i][j] == 'E')
		{
			path->map[i][j] = '0';
			return (0);
		}
		dir.up = find_path_e(path, i - 1, j);
		if (dir.up == 0)
			return (0);
		dir.left = find_path_e(path, i, j - 1);
		if (dir.left == 0)
			return (0);
		dir.down = find_path_e(path, i + 1, j);
		if (dir.down == 0)
			return (0);
		dir.right = find_path_e(path, i, j + 1);
		if (dir.right == 0)
			return (0);
	}
	return (1);
}
