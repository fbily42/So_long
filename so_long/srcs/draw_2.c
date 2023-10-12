/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 03:31:55 by fbily             #+#    #+#             */
/*   Updated: 2022/08/12 03:32:14 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	which_player(t_vars *vars)
{
	if (vars->dir == 0)
	{
		draw_sprite(&vars->image, &vars->player_h,
			vars->pos.x, vars->pos.y);
	}
	if (vars->dir == 1)
	{
		draw_sprite(&vars->image, &vars->player_b,
			vars->pos.x, vars->pos.y);
	}
	if (vars->dir == 2)
	{
		draw_sprite(&vars->image, &vars->player_g,
			vars->pos.x, vars->pos.y);
	}
	if (vars->dir == 3)
	{
		draw_sprite(&vars->image, &vars->player_d,
			vars->pos.x, vars->pos.y);
	}
}
