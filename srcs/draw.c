/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:33:22 by fbily             #+#    #+#             */
/*   Updated: 2022/08/12 01:26:31 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_color(t_data *image, int x, int y, unsigned int color)
{
	char	*dst;

	dst = image->addr + y * image->size_line + x * image->bpp / 8;
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_data *image, int x, int y)
{
	char	*dst;

	dst = image->addr + y * image->size_line + x * 4;
	return (*(unsigned int *)dst);
}

void	draw_sprite(t_data *image, t_data *sprite, int x, int y)
{
	size_t			i;
	size_t			j;
	unsigned int	color;

	i = 0 ;
	while (i < CELL_H)
	{
		j = 0;
		while (j < CELL_W)
		{
			color = get_color(sprite, j, i);
			if (color != 0x0)
				put_color(image, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_image(t_vars *vars)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		vars->pos.x = 0;
		while (vars->map.map[i][j])
		{
			which_sprite(vars, vars->map.map[i][j]);
			vars->pos.x += CELL_W;
			j++;
		}
		vars->pos.y += CELL_H;
		i++;
	}
}

void	which_sprite(t_vars *vars, char c)
{
	if (c == '1')
	{
		draw_sprite(&vars->image, &vars->wall,
			vars->pos.x, vars->pos.y);
	}
	if (c == '0')
	{
		draw_sprite(&vars->image, &vars->ground,
			vars->pos.x, vars->pos.y);
	}
	if (c == 'E')
	{
		draw_sprite(&vars->image, &vars->exit,
			vars->pos.x, vars->pos.y);
	}
	if (c == 'P')
	{
		draw_sprite(&vars->image, &vars->player,
			vars->pos.x, vars->pos.y);
	}
	if (c == 'C')
	{
		draw_sprite(&vars->image, &vars->object,
			vars->pos.x, vars->pos.y);
	}
}
