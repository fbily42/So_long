/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:50:42 by fbily             #+#    #+#             */
/*   Updated: 2022/07/26 22:03:39 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (!argv[1] || argc != 2)
		return (ft_printf("Error arguments\n"));
	if (parsing(argv[1]) != 0)
		return (ft_printf("Error extension\n"));
	ft_printf("map ok\n");
	return (0);
}
