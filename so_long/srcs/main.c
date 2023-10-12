/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:50:42 by fbily             #+#    #+#             */
/*   Updated: 2022/09/19 19:43:32 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	init_struct(&vars);
	if (!argv[1] || argc != 2 || parsing(&vars, argv[1]) != 0)
		return (ft_printf("Error\nMap incorrect\n"));
	if (vars.map.nb_ligne > 64 || vars.map.size_line > 64)
		return (clean_all(&vars), ft_printf("Error\nMap trop grande\n"));
	if (check_path(vars, argv[1]) != 0)
		return (clean_all(&vars), ft_printf("Error\nMap non terminable\n"));
	get_window_size(&vars);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (clean_all(&vars), ft_printf("Error\nFail mlx_init\n"));
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "So_long");
	if (vars.win == NULL)
		return (clean_all(&vars), ft_printf("Error\nFail new_window\n"));
	if (create_images(&vars) != 0)
		return (clean_all(&vars), ft_printf("Error\nTextures invalides\n"));
	get_images_addr(&vars);
	mlx_hook(vars.win, 3, 1L << 1, keypress, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_window, &vars);
	mlx_loop_hook(vars.mlx, render_image, &vars);
	mlx_loop(vars.mlx);
	clean_all(&vars);
	return (0);
}
