/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:00:15 by fbily             #+#    #+#             */
/*   Updated: 2022/09/20 18:24:38 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libs/Libft/includes/libft.h"
# include "../Libs/ft_printf/includes/libftprintf.h"
# include "../Libs/mlx_linux/mlx.h"

# define CELL_W 64
# define CELL_H 64

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_dir
{
	int	up;
	int	down;
	int	left;
	int	right;
}				t_dir;

typedef struct s_map
{
	size_t				size_line;
	char				**map;
	int					nb_ligne;
	int					count_p;
	int					count_c;
	int					count_e;
	t_pos				player;

}				t_map;

typedef struct s_path
{
	char	**map;
	char	**visited;
	t_pos	start;
	t_pos	target;
	int		nb_ligne;
	size_t	size_line;
	int		count_c;
	int		count_e;
}				t_path;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_data			image;
	t_data			wall;
	t_data			ground;
	t_data			player_h;
	t_data			player_b;
	t_data			player_g;
	t_data			player_d;
	t_data			object;
	t_data			exit;
	t_pos			pos;
	int				moves;
	int				dir;
	unsigned int	width;
	unsigned int	height;
}				t_vars;

/****************		PARSING		*******************/

void			find_p(t_vars *vars);
char			**get_map(char *file_path, char **map, int nb_ligne);
int				parsing(t_vars *vars, char *argv);
int				count_element(t_map *map);
int				count_lignes(char *file);
int				check_size(t_map *map);
int				parse_map(t_map *map);
int				check_map(t_map *map);
int				count_p(t_vars *vars);

/****************		Draw		*******************/

unsigned int	get_color(t_data *image, int x, int y);
void			put_color(t_data *image, int x, int y, unsigned int color);
void			draw_sprite(t_data *image, t_data *sprite, int x, int y);
void			which_sprite(t_vars *vars, char c);
void			draw_image(t_vars *vars);
void			which_player(t_vars *vars);

/****************		MLX_Utils		*******************/

void			switch_position(t_vars *vars, size_t i, size_t j);
void			get_window_size(t_vars *vars);
void			get_images_addr(t_vars *vars);
void			create_player(t_vars *vars);
void			clear_window(t_vars *vars);
int				keypress(int key, t_vars *vars);
int				create_images(t_vars *vars);
int				close_window(t_vars *vars);
int				render_image(t_vars *vars);

/****************		Cleanning		*******************/

void			destroy_images(t_vars *vars);
void			init_struct(t_vars *vars);
void			clean_all(t_vars *vars);
void			clean_map(char **map);

/****************		Pathfinding		*******************/

void			find_player(t_path *path);
void			erase_map(char ***map);
void			print_map(char **map);
int				find_path_c(t_path *path, int i, size_t j);
int				find_path_e(t_path *path, int i, size_t j);
int				is_safe(int i, size_t j, t_path *path);
int				check_path(t_vars vars, char *argv);
int				try_find_paths(t_path *path);

#endif