/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:17:42 by fbily             #+#    #+#             */
/*   Updated: 2022/08/12 06:25:34 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	switch_position(t_vars *vars, size_t i, size_t j)
{
	if (vars->map.map[i][j] == '1')
		return ;
	else if (vars->map.map[i][j] == 'E' && vars->map.count_c != 0)
		return ;
	else if (vars->map.map[i][j] == 'E' && vars->map.count_c == 0)
	{	
		vars->moves++;
		ft_printf("%d\n", vars->moves);
		mlx_loop_end(vars->mlx);
	}
	else
	{
		vars->map.map[vars->map.player.y][vars->map.player.x] = '0';
		if (count_p(vars) > 0)
			return ;
		if (vars->map.map[i][j] == 'C')
			vars->map.count_c--;
		vars->map.map[i][j] = 'P';
		vars->moves++;
		ft_printf("%d\n", vars->moves);
	}
}

void	get_window_size(t_vars *vars)
{
	vars->width = CELL_W * vars->map.size_line;
	vars->height = CELL_H * vars->map.nb_ligne;
}

void	clear_window(t_vars *vars)
{
	ft_bzero(vars->image.addr, vars->height * vars->width * 4);
}

int	close_window(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}
