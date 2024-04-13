/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check_initializations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:41:49 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/13 18:10:59 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_path	*init_path(t_path *path)
{
	path = malloc(sizeof(t_path));
	if (!path)
		map_path_errors(2, path);
	path->original_map = NULL;
	path->flood_map = NULL;
	path->nl_count = 0;
	path->player_found = false;
	path->x = 0;
	path->y = 0;
	path->max_x = 0;
	path->max_y = 0;
	return (path);
}

int	init_original_map(t_path *path, int map)
{
	int		y;
	char	*line;

	y = 0;
	path->original_map = malloc(sizeof(char *) * (path->nl_count + 1));
	if (!path->original_map)
		return (-1);
	line = get_next_line(map);
	if (!line)
		return (-1);
	path->original_map[y++] = ft_strdup(line);
	while (1)
	{
		free(line);
		line = get_next_line(map);
		path->original_map[y] = ft_strdup(line);
		if (ft_strchr_index(line, '\n') == -1)
			break ;
		if (!path->original_map[y++])
			return (-1);
	}
	if (line)
		free(line);
	path->original_map[++y] = NULL;
	return (0);
}

char	**map_copy(t_path *path)
{
	int		crstr;
	int		max;

	crstr = 0;
	max = 0;
	while (path->original_map[crstr])
	{
		crstr++;
		max++;
	}
	crstr = 0;
	path->flood_map = malloc(sizeof(char *) * (max + 1));
	if (!path->flood_map)
		return (NULL);
	while (crstr < max)
	{
		path->flood_map[crstr] = ft_strdup(path->original_map[crstr]);
		if (!path->flood_map[crstr])
			return (NULL);
		crstr++;
	}
	path->flood_map[crstr] = NULL;
	return (path->flood_map);
}

int	find_max_y(char **flood_map)
{
	int	i;

	i = 0;
	while (flood_map[i])
		i++;
	return (i);
}

void	line_count(t_path *path, int map)
{
	char	*line;

	line = get_next_line(map);
	if (!line)
		path->nl_count = -1;
	path->nl_count = 1;
	while (line)
	{
		free(line);
		line = get_next_line(map);
		if (line)
			path->nl_count++;
	}
}
