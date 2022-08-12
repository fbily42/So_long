/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:20:16 by fbily             #+#    #+#             */
/*   Updated: 2022/08/12 02:22:53 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_images(t_vars *vars)
{
	if (vars->ground.img != NULL)
		mlx_destroy_image(vars->mlx, vars->ground.img);
	if (vars->wall.img != NULL)
		mlx_destroy_image(vars->mlx, vars->wall.img);
	if (vars->object.img != NULL)
		mlx_destroy_image(vars->mlx, vars->object.img);
	if (vars->player.img != NULL)
		mlx_destroy_image(vars->mlx, vars->player.img);
	if (vars->exit.img != NULL)
		mlx_destroy_image(vars->mlx, vars->exit.img);
	if (vars->image.img != NULL)
		mlx_destroy_image(vars->mlx, vars->image.img);
}

void	clean_all(t_vars *vars)
{
	destroy_images(vars);
	if (vars->mlx != NULL)
	{
		if (vars->win != NULL)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	if (vars->map.map != NULL)
		clean_map(vars->map.map);
}

void	clean_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	init_struct(t_vars *vars)
{
	vars->ground.img = NULL;
	vars->wall.img = NULL;
	vars->object.img = NULL;
	vars->player.img = NULL;
	vars->exit.img = NULL;
	vars->image.img = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map.map = NULL;
	vars->moves = 0;
}
