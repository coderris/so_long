/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:55:08 by lanton-m          #+#    #+#             */
/*   Updated: 2025/09/29 11:40:55 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363

# define CELL_SIZE 32

typedef struct s_flood_data
{
	char	**mat;
	int		rows;
	int		cols;
	int		*collectibles;
	int		*exit_found;
}	t_flood_data;

typedef struct s_player_search
{
	char	**mat;
	int		rows;
	int		cols;
	int		*x;
	int		*y;
}	t_player_search;

typedef struct s_game_objs
{
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*collectible;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	void	*floor;
}	t_game_objs;

typedef struct s_game_positions
{
	int	player_row;
	int	player_col;
}	t_game_positions;

typedef struct s_game_data
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
	int	count_movements;
}	t_game_data;

typedef struct s_game_resolutions
{
	int		settings_map_width;
	int		settings_map_height;
	char	*settings_name_window;
	char	*settings_name_map;
}	t_game_resolutions;

typedef struct s_map_data
{
	int					cols_matrice;
	int					rows_matrice;
	int					size_matrice;
	char				**matrice;
	t_game_resolutions	resolutions;
}	t_map_data;

typedef struct s_game_instance
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_map_data			map_init;
	t_game_positions	positions_init;
	t_game_data			game_data;
	t_game_resolutions	resolutions_init;
	t_game_objs			game_objs;
}	t_game_instance;

int		main(int argc, char **argv);
void	ft_struct_init(t_game_instance *game_init);
void	ft_start_game(t_game_instance *game_init);
void	ft_handle_error(int result, t_game_instance *game_init);
void	ft_initialize_game(t_game_instance *game_init);
void	ft_img_init(t_game_instance *game_init);
void	ft_load_player_textures(t_game_instance *game_init);
void	ft_load_game_textures(t_game_instance *game_init);
void	ft_check_img(t_game_instance *game_init, void **image, char *path);
int		ft_check_keyboard(int key, t_game_instance *game_init);
int		ft_non_special(int key, t_game_instance *game_init);
int		ft_exit_program(t_game_instance *game_init);
int		ft_open_map(char *map, t_game_instance *game_init);
int		ft_map_dimensions(t_game_instance *game_init);
int		get_cols_count(t_map_data *map_init);
int		ft_read_map(int fd, t_game_instance *game_init);
char	**ft_read_all_lines(int fd);
char	**ft_realloc_matrix(char **old_matrix, int old_count, int new_capacity);
void	ft_free_string_array(char **array, int count);
int		ft_check_read(t_game_instance *game_init);
int		ft_map_extension(char *map);
int		ft_is_valid_map(t_game_instance *game_init);
int		ft_is_map_shape_valid(t_game_instance *game_init);
int		ft_check_all_rows_length(t_game_instance *game_init, int ref_len);
int		ft_get_row_length(t_game_instance *game_init, int row);
int		ft_is_wall(t_game_instance *game_init);
int		ft_count_map_objects(t_game_instance *game_init);
void	ft_init_counters(t_game_instance *game_init);
int		ft_process_map_chars(t_game_instance *game_init);
int		ft_count_char(t_game_instance *game_init, char c);
int		ft_have_requires(t_game_instance *game_init);
int		ft_is_map_resoluble(t_game_instance *game_init);
void	ft_gameplay_start(t_game_instance *game_init);
int		ft_events_pressed(t_game_instance *game_init, int column, int row);
void	ft_handle_movement(t_game_instance *game_init, int new_row, 
			int new_col, int current_tile);
void	ft_win(t_game_instance *game_init);
int		ft_print_shell(t_game_instance *game_init);
void	ft_locate_player(t_game_instance *game_init);
int		ft_map_draw(t_game_instance *game_init);
void	ft_draw_tile(t_game_instance *game_init, int row, int column);
void	ft_draw_exit(t_game_instance *game_init, int column, int row);
void	ft_set(t_game_instance *game_init, void *img, int wid, int hgt);
void	ft_free_map(t_game_instance *game_init);
void	ft_free_img(t_game_instance *game_init);
void	ft_free_player_textures(t_game_instance *game_init);
void	ft_free_game_textures(t_game_instance *game_init);
void	ft_cleanup(t_game_instance *game_init);
int		ft_strcmp(const char *s1, const char *s2);

#endif
