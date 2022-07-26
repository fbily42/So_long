/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:50:21 by fbily             #+#    #+#             */
/*   Updated: 2022/07/26 22:04:44 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parsing(char *argv)
{
	char	*pts;

	pts = ft_strrchr(argv, '.');
	if (pts == NULL || ft_strncmp(pts, ".ber", 5) != 0)
		return (1);
	return (0);
}
