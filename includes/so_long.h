/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:00:15 by fbily             #+#    #+#             */
/*   Updated: 2022/08/08 16:00:29 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libs/Libft/includes/libft.h"
# include "../Libs/ft_printf/includes/libftprintf.h"
# include "../Libs/mlx_linux/mlx.h"

typedef struct s_map
{
	size_t				size_line;
	char				**map;
	int					nb_ligne;
	int					count_p;
	int					count_c;
	int					count_e;

}				t_map;

int		parsing(char *argv);
int		count_lignes(char *file);
char	**get_map(char *file_path, char **map, int nb_ligne);
void	clean_map(char **map);

int		parse_map(t_map *map);
int		check_map(t_map *map);
int		check_size(t_map *map);
int		count_element(t_map *map);

#endif