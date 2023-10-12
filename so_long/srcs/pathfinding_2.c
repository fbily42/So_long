/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:40:50 by fbily             #+#    #+#             */
/*   Updated: 2022/09/20 18:19:28 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	erase_map(char ***map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)[i])
	{
		j = 1;
		while ((*map)[i][j])
		{
			if ((*map)[i][j] != '1' && (*map)[i][j] != '\n')
				(*map)[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	is_safe(int i, size_t j, t_path *path)
{
	if ((i >= 0 && i < path->nb_ligne) && (j > 0 && j < path->size_line))
		return (0);
	else
		return (1);
}

void	find_player(t_path *path)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (path->map[i])
	{
		j = 0;
		while (path->map[i][j])
		{
			if (path->map[i][j] == 'P')
			{
				path->start.x = j;
				path->start.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}
