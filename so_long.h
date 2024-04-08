/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:51:43 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/08 16:25:33 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <errno.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"

# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


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
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	t_path	*path;
	t_img	*imgs;
}	t_game;

char	*ft_strdup(const char *s);

// Free-functions
void	free_all(t_game *so_long);
int		ft_freearray(char **arr);
void	free_imgs(t_img *imgs);
void	free_path(t_path *path);
void	free_floodmap(t_path *path);

// Map validation -> Check file type, valid characters, size etc.
void	check_map(char *argv[]);
int		finish_read(int map);
int		check_file_type(char *map_filename);
int		count_each_line(int map);
int		check_map_elements(int map, t_count *counter);
int		check_invalid_chars(char *line);
int		check_walls(char *line);
void	check_collectibles(char	*line, t_count *counter);
void	check_position(char	*line, t_count *counter);
void	check_exit(char	*line, t_count *counter);

// Map validation -> Check if there is a valid path to reach all collectibles
// and also the exit.
t_path	*check_map_path(char *argv[]);
t_path	*init_path(t_path *path);
int		init_original_map(t_path *path, int map);
char	**map_copy(t_path *path);
int		find_max_y(char **flood_map);
void	line_count(t_path *path, int map);
int		find_valid_path(t_path *path);
void	set_player_start_coordinates(t_path *path);
int		check_flood_map(char **flood_map, char **original_map);
char	**fill_flood_map(t_path *path, char **flood_map, int x, int y);

// Errors
void	map_errors(int error_code, t_count *counter);
void	map_path_errors(int error_code, t_path *path);
void	init_window_errors(int error_code, t_path **path, t_img **imgs);

#endif