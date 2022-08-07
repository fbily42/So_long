/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:00:15 by fbily             #+#    #+#             */
/*   Updated: 2022/07/29 21:40:58 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libs/Libft/includes/libft.h"
# include "../Libs/ft_printf/includes/libftprintf.h"
# include "../Libs/mlx_linux/mlx.h"

int		parsing(char *argv);
int		count_lignes(char *file);
char	**get_map(char *file_path, char **map);
void	clean_map(char **map);

#endif