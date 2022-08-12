/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 23:17:29 by fbily             #+#    #+#             */
/*   Updated: 2022/08/12 03:42:34 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keypress(int key, t_vars *vars)
{
	if (key == 65307)
		mlx_loop_end(vars->mlx);
	if (key == 65362 || key == 119)
	{	
		switch_position(vars, (vars->map.player.y - 1), vars->map.player.x);
		vars->dir = 0;
	}
	if (key == 65364 || key == 115)
	{
		switch_position(vars, (vars->map.player.y + 1), vars->map.player.x);
		vars->dir = 1;
	}
	if (key == 65361 || key == 97)
	{
		switch_position(vars, vars->map.player.y, (vars->map.player.x - 1));
		vars->dir = 2;
	}
	if (key == 65363 || key == 100)
	{
		switch_position(vars, vars->map.player.y, (vars->map.player.x + 1));
		vars->dir = 3;
	}
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
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "textures/exit.xpm",
			&vars->exit.width, &vars->exit.height);
	create_player(vars);
	if (vars->image.img == NULL || vars->ground.img == NULL
		|| vars->wall.img == NULL || vars->object.img == NULL
		|| vars->player_h.img == NULL || vars->exit.img == NULL
		|| vars->player_b.img == NULL || vars->player_g.img == NULL
		|| vars->player_d.img == NULL)
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
	vars->player_h.addr = mlx_get_data_addr(vars->player_h.img,
			&vars->player_h.bpp, &vars->player_h.size_line,
			&vars->player_h.endian);
	vars->player_b.addr = mlx_get_data_addr(vars->player_b.img,
			&vars->player_b.bpp, &vars->player_b.size_line,
			&vars->player_b.endian);
	vars->player_g.addr = mlx_get_data_addr(vars->player_g.img,
			&vars->player_g.bpp, &vars->player_g.size_line,
			&vars->player_g.endian);
	vars->player_d.addr = mlx_get_data_addr(vars->player_d.img,
			&vars->player_d.bpp, &vars->player_d.size_line,
			&vars->player_d.endian);
	vars->exit.addr = mlx_get_data_addr(vars->exit.img, &vars->exit.bpp,
			&vars->exit.size_line, &vars->exit.endian);
}

void	create_player(t_vars *vars)
{
	vars->player_h.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/player_haut.xpm", &vars->player_h.width,
			&vars->player_h.height);
	vars->player_b.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/player_bas.xpm", &vars->player_b.width,
			&vars->player_b.height);
	vars->player_d.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/player_droite.xpm", &vars->player_d.width,
			&vars->player_d.height);
	vars->player_g.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/player_gauche.xpm", &vars->player_g.width,
			&vars->player_g.height);
}
