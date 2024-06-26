/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:25:50 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 17:14:43 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

char	**fill_flood_map(t_path *path, char **flood_map, int x, int y)
{
	if (y + 1 < path->max_y && flood_map[y + 1][x] != '\n' 
		&& flood_map[y + 1][x] != '1' && flood_map[y + 1][x] != 'X')
	{
		flood_map[y + 1][x] = 'X';
		fill_flood_map(path, flood_map, x, y + 1);
	}
	if (y - 1 >= 0 && flood_map[y - 1][x] != '\n' 
		&& flood_map[y - 1][x] != '1' && flood_map[y - 1][x] != 'X')
	{
		flood_map[y - 1][x] = 'X';
		fill_flood_map(path, flood_map, x, y - 1);
	}
	if (x + 1 < path->max_x && flood_map[y][x + 1] != '\n' 
		&& flood_map[y][x + 1] != '1' && flood_map[y][x + 1] != 'X')
	{
		flood_map[y][x + 1] = 'X';
		fill_flood_map(path, flood_map, x + 1, y);
	}
	if (x - 1 >= 0 && flood_map[y][x - 1] != '\n' 
		&& flood_map[y][x - 1] != '1' && flood_map[y][x - 1] != 'X')
	{
		flood_map[y][x - 1] = 'X';
		fill_flood_map(path, flood_map, x - 1, y);
	}
	return (flood_map);
}

int	check_flood_map(char **flood_map, char **original_map)
{
	int	x;
	int	y;

	y = 0;
	while (original_map[y])
	{
		x = 0;
		while (original_map[y][x])
		{
			if (original_map[y][x] == 'C' || original_map[y][x] == 'E')
			{
				if (flood_map[y][x] != 'X')
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	set_player_start_coordinates(t_path *path)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (path->original_map[y])
	{
		x = 0;
		while (path->original_map[y][x])
		{
			if (path->original_map[y][x] == 'P')
			{
				path->player_found = true;
				break ;
			}
			x++;
		}
		if (path->player_found)
			break ;
		y++;
	}
	path->x = x;
	path->y = y;
}

int	find_valid_path(t_path *path)
{
	set_player_start_coordinates(path);
	path->flood_map = map_copy(path);
	if (!path->flood_map)
		return (-1);
	path->max_x = ft_strlen(path->flood_map[0]);
	path->max_y = find_max_y(path->flood_map);
	path->flood_map = fill_flood_map(path, path->flood_map, path->x, path->y);
	if (check_flood_map(path->flood_map, path->original_map) == -1)
		return (-1);
	return (0);
}

void	check_map_path(char *argv[], t_game **sl)
{
	int		map;

	init_path((*sl));
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_path_errors(1, sl);
	line_count((*sl)->path, map);
	if ((*sl)->path->nl_count == -1)
		map_path_errors(2, sl);
	if (close(map) == -1)
		map_path_errors(3, sl);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_path_errors(1, sl);
	if (init_original_map((*sl)->path, map) == -1)
		map_path_errors(2, sl);
	if (close(map) == -1)
		map_path_errors(3, sl);
	if (find_valid_path((*sl)->path) == -1)
		map_path_errors(4, sl);
}
