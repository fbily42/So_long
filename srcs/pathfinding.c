/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:15:49 by fbily             #+#    #+#             */
/*   Updated: 2022/11/07 18:53:55 by fbily            ###   ########.fr       */
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
	if (path.map == NULL || path.visited == NULL)
		return (1);
	path.count_c = vars.map.count_c;
	path.count_e = vars.map.count_e;
	path.nb_ligne = vars.map.nb_ligne;
	path.size_line = vars.map.size_line;
	find_player(&path);
	if (try_find_paths(&path) == 1)
		return (clean_map(path.map), clean_map(path.visited), 1);
	return (clean_map(path.map), clean_map(path.visited), 0);
}

int	try_find_paths(t_path *path)
{
	while (path->count_c > 0)
	{
		erase_map(&path->visited);
		if (find_path_c(path, path->start.y, path->start.x) == 0)
			path->count_c--;
		else
			return (1);
	}
	while (path->count_e > 0)
	{
		erase_map(&path->visited);
		if (find_path_e(path, path->start.y, path->start.x) == 0)
			path->count_e--;
		else
			return (1);
	}
	return (0);
}

int	find_path_c(t_path *path, int i, size_t j)
{
	t_dir	dir;

	if (is_safe(i, j, path) == 0 && path->map[i][j] != '1'
		&& path->visited[i][j] != 'X')
	{
		path->visited[i][j] = 'X';
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

int	find_path_e(t_path *path, int i, size_t j)
{
	t_dir	dir;

	if (is_safe(i, j, path) == 0 && path->map[i][j] != '1'
		&& path->visited[i][j] != 'X')
	{
		path->visited[i][j] = 'X';
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
