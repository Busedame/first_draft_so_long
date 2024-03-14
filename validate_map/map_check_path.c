/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:25:50 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/14 17:49:13 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	parse_line_for_collectibles(t_path *path, char *line)
{
	int	i;

	i = 0;
	path->tot_collect = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'C')
			path->tot_collect++;
		i++;
	}
	return (path->tot_collect);
}

static int	count_collectibles(t_path *path, int map)
{
	char	*line;

	line = get_next_line(map);
	if (!line)
		return (-1);
	parse_line_for_collectibles(path, line);
	path->nl_count = 1;
	while (line)
	{
		free(line);
		line = get_next_line(map);
		path->nl_count++;
		if (ft_strchr_index(line, '\n') == -1)
		{
			path->tot_collect += parse_line_for_collectibles(path, line);
			break ;
		}
		path->tot_collect += parse_line_for_collectibles(path, line);
	}
	if (line)
		free(line);
	return (path->tot_collect);
}

static int	init_map_array(t_path *path, int map)
{
	int		y;
	char	*line;

	y = 0;
	path->map_array = malloc(sizeof(char *) * path->nl_count + 1);
	if (!path->map_array)
		return (-1);
	line = get_next_line(map);
	if (!line)
		return (-1);
	path->map_array[y++] = ft_strdup(line);
	while (1)
	{
		free(line);
		line = get_next_line(map);
		if (ft_strchr_index(line, '\n') == -1)
		{
			path->map_array[y] = ft_strdup(line);
			break ;
		}
		path->map_array[y] = ft_strdup(line);
		if (!path->map_array[y])
			return (-1);
		y++;
	}
	path->map_array[++y] = NULL;
	y = 0;
	while (path->map_array[y])
		ft_printf("%s", path->map_array[y++]);
	return (0);
}

void	check_map_path(char *argv[])
{
	int		map;
	t_path	*path;

	path = malloc(sizeof(t_path));
	if (!path)
		map_path_errors(2, path);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_path_errors(1, path);
	path->tot_collect = count_collectibles(path, map);
	if (path->tot_collect == -1)
		map_path_errors(2, path);
	if (close(map) == -1)
		map_path_errors(3, path);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_path_errors(1, path);
	if (init_map_array(path, map) == -1)
		map_path_errors(2, path);
	if (close(map) == -1)
		map_path_errors(3, path);
	free_path(path);
}
