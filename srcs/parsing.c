/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:50:21 by fbily             #+#    #+#             */
/*   Updated: 2022/07/29 14:59:42 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parsing(char *argv)
{
	char	*pts;
	int		i;
	int		fd;

	i = 0;
	pts = ft_strrchr(argv, '.');
	if (pts == NULL || ft_strncmp(pts, ".ber", 5) != 0 || *pts == *argv)
		return (1);
	fd = open(argv, __O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), 1);
	i = count_lignes(argv);
	ft_printf("La map possede %d lignes\n", i);
	return (0);
}

int	count_lignes(char *file)
{
	char	buf[1];
	int		fd;
	int		count;
	int		readed;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		readed = read(fd, buf, 1);
		if (buf[0] == '\n')
			count++;
		if (readed == 0)
			break ;
	}
	close(fd);
	return (count);
}
