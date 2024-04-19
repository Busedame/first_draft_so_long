/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:51:43 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/19 13:27:46 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define W_UP 119
# define S_DOWN 115
# define A_LEFT 97
# define D_RIGHT 100
# include "ft_printf.h"
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <errno.h>
# include <stdbool.h>

typedef struct s_count
{
	int	count_e;
	int	count_p;
	int	count_c;
	int	line_count;
}	t_count;

typedef struct s_path
{
	int		nl_count;
	char	**original_map;
	char	**flood_map;
	bool	player_found;
	int		x;
	int		y;
	int		max_x;
	int		max_y;
}	t_path;

typedef struct s_img
{
	char	*me;
	char	*wall;
	char	*shop;
	char	*food;
	char	*bed;
	char	*back;
	char	*exit;
	char	*win;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		plc_x;
	int		plc_y;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		win_height;
	int		win_width;
	bool	display_start;
	bool	window_start;
	bool	game_ended;
	int		moves;
	t_path	*path;
	t_img	*imgs;
}	t_game;

// Standard-functions
char	*ft_strdup(const char *s);
int		count_array_length(t_path *path);

// Free-functions
void	free_all(t_game **sl);
int		ft_freearray(char **arr);
void	free_imgs(t_img *imgs);
void	free_path(t_path *path);
void	free_line(char *line);

// Map validation -> Check file type, valid characters, size etc.
void	validate_map(char *argv[], t_game **sl);
void	check_map(char *argv[], t_game **sl);
int		finish_read(int map, char **line);
int		check_file_type(char *map_filename);
int		count_each_line(int map);
int		check_map_elements(int map, t_count *counter);
int		check_invalid_chars(char *line);
int		check_walls(char *line);
void	check_collectibles(char	*line, t_count *counter);
void	check_position(char	*line, t_count *counter);
void	check_exit(char	*line, t_count *counter);

// Map validation -> Check if there is a valid path to reach collectibles+exit.
void	check_map_path(char *argv[], t_game **sl);
void	init_path(t_game *sl);
int		init_original_map(t_path *path, int map);
char	**map_copy(t_path *path);
int		find_max_y(char **flood_map);
void	line_count(t_path *path, int map);
int		find_valid_path(t_path *path);
void	set_player_start_coordinates(t_path *path);
int		check_flood_map(char **flood_map, char **original_map);
char	**fill_flood_map(t_path *path, char **flood_map, int x, int y);

// Game initialization
void	init_struct(t_game **sl);
void	init_game(t_game **sl);
void	init_images(t_game *sl);
void	set_images(t_game *sl);
void	init_map_in_window(t_game *sl, void *mlx, void *mlx_win);
void	build_map_in_window(t_game *sl, void *mlx, void *mlx_win, int y);
void	build_wall(t_game *sl, void *mlx, void *mlx_win, int size);
void	build_player(t_game *sl, void *mlx, void *mlx_win, int size);
void	build_collectible(t_game *sl, void *mlx, void *mlx_win, int size);
void	build_exit(t_game *sl, void *mlx, void *mlx_win, int size);
void	build_background(t_game *sl, void *mlx, void *mlx_win, int size);
void	find_player(t_game *sl);

// Running the game
void	run_game(t_game **sl);
int		key_hook(int keycode, t_game *sl);
void	move_player(t_game *sl, int dir);
void	is_finished(t_game *sl);
int		close_hook_cross(t_game *sl);

// Errors
void	map_errors(int error_code, t_count *counter, t_game **sl);
void	map_path_errors(int error_code, t_game **sl);
void	game_errors(int error_code, t_game **sl);
void	image_error(void *img, t_game **sl);

#endif