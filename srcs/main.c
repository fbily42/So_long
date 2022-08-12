/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:50:42 by fbily             #+#    #+#             */
/*   Updated: 2022/08/12 02:26:46 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_struct(&vars);
	if (!argv[1] || argc != 2 || parsing(&vars, argv[1]) != 0)
		return (ft_printf("Error\n Map incorrect\n"));
	get_window_size(&vars);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (clean_all(&vars), ft_printf("Error\n Fail mlx_init\n"));
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "So_long");
	if (vars.win == NULL)
		return (clean_all(&vars), ft_printf("Error\n Fail new_window\n"));
	if (create_images(&vars) != 0)
		return (clean_all(&vars), ft_printf("Error\n Textures invalides\n"));
	get_images_addr(&vars);
	mlx_hook(vars.win, 2, 1L << 0, keypress, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
	mlx_loop_hook(vars.mlx, render_image, &vars);
	mlx_loop(vars.mlx);
	clean_all(&vars);
	return (0);
}
