/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:51:43 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/14 17:40:02 by nholbroo         ###   ########.fr       */
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

typedef struct s_count
{
	int	count_e;
	int	count_p;
	int	count_c;
	int	line_count;
}	t_count;

typedef struct s_path
{
	int		tot_collect;
	int		curr_collect;
	int		nl_count;
	char	**map_array;
}	t_path;

typedef struct s_game
{
	int	count_e;
	int	count_p;
	int	count_c;
	int	line_count;
}	t_game;

char	*ft_strdup(const char *s);

// Free-functions
void	free_all(t_game *so_long);
int		ft_freearray(char **arr);
void	free_path(t_path *path);

// Map validation
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
void	check_map_path(char *argv[]);

// Errors
void	map_errors(int error_code, t_count *counter);
void	map_path_errors(int error_code, t_path *path);

#endif