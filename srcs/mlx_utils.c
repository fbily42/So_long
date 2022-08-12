/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:17:29 by fbily             #+#    #+#             */
/*   Updated: 2022/08/12 02:22:05 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keypress(int key, t_vars *vars)
{
	if (key == 65307)
		mlx_loop_end(vars->mlx);
	if (key == 65362 || key == 119)
		switch_position(vars, (vars->map.player.y - 1), vars->map.player.x);
	if (key == 65364 || key == 115)
		switch_position(vars, (vars->map.player.y + 1), vars->map.player.x);
	if (key == 65361 || key == 97)
		switch_position(vars, vars->map.player.y, (vars->map.player.x - 1));
	if (key == 65363 || key == 100)
		switch_position(vars, vars->map.player.y, (vars->map.player.x + 1));
	return (0);
}

int	render_image(t_vars *vars)
{
	vars->pos.x = 0;
	vars->pos.y = 0;
	find_p(vars);
	clear_window(vars);
	draw_image(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	return (0);
}

int	create_images(t_vars *vars)
{
	vars->image.img = mlx_new_image(vars->mlx, vars->width, vars->height);
	vars->ground.img = mlx_xpm_file_to_image(vars->mlx, "textures/ground.xpm",
			&vars->ground.width, &vars->ground.height);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "textures/wall.xpm",
			&vars->wall.width, &vars->wall.height);
	vars->object.img = mlx_xpm_file_to_image(vars->mlx, "textures/object.xpm",
			&vars->object.width, &vars->object.height);
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, "textures/player.xpm",
			&vars->player.width, &vars->player.height);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm",
			&vars->exit.width, &vars->exit.height);
	if (vars->image.img == NULL || vars->ground.img == NULL
		|| vars->wall.img == NULL || vars->object.img == NULL
		|| vars->player.img == NULL || vars->exit.img == NULL)
		return (1);
	return (0);
}

void	get_images_addr(t_vars *vars)
{
	vars->image.addr = mlx_get_data_addr(vars->image.img, &vars->image.bpp,
			&vars->image.size_line, &vars->image.endian);
	vars->ground.addr = mlx_get_data_addr(vars->ground.img, &vars->ground.bpp,
			&vars->ground.size_line, &vars->ground.endian);
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, &vars->wall.bpp,
			&vars->wall.size_line, &vars->wall.endian);
	vars->object.addr = mlx_get_data_addr(vars->object.img, &vars->object.bpp,
			&vars->object.size_line, &vars->object.endian);
	vars->player.addr = mlx_get_data_addr(vars->player.img, &vars->player.bpp,
			&vars->player.size_line, &vars->player.endian);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img, &vars->exit.bpp,
			&vars->exit.size_line, &vars->exit.endian);
}

int	close_window(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
