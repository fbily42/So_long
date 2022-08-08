/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:50:42 by fbily             #+#    #+#             */
/*   Updated: 2022/08/08 15:47:27 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (!argv[1] || argc != 2 || parsing(argv[1]) != 0)
		return (ft_printf("Error\n"));
	ft_printf("\nMap OK\n");
	return (0);
}
