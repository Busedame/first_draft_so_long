/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:24 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 17:14:51 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

int	finish_read(int map, char *line)
{
	if (line)
		free_line(line);
	line = get_next_line(map);
	while (line)
	{
		free_line(line);
		line = get_next_line(map);
	}
	return (-1);
}

int	check_file_type(char *map_filename)
{
	int	i;

	i = ft_strlen(map_filename) - 1;
	if (i >= 4)
	{
		if (map_filename[i] != 'r')
			return (-1);
		if (map_filename[i - 1] != 'e')
			return (-1);
		if (map_filename[i - 2] != 'b')
			return (-1);
		if (map_filename[i - 3] != '.')
			return (-1);
		if (map_filename[i - 4] == '\0')
			return (-1);
	}
	else
		return (-1);
	return (0);
}

void	check_map(char *argv[], t_game **sl)
{
	int		map;
	t_count	*counter;

	counter = malloc (sizeof(t_count));
	if (!counter)
		map_errors(5, counter, sl);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_errors(1, counter, sl);
	if (check_file_type(argv[1]) == -1)
		map_errors(2, counter, sl);
	if (count_each_line(map) == -1)
	{
		close(map);
		map_errors(3, counter, sl);
	}
	if (close(map) == -1)
		map_errors(4, counter, sl);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_errors(1, counter, sl);
	if (check_map_elements(map, counter) == -1)
		map_errors(3, counter, sl);
	if (close(map) == -1)
		map_errors(4, counter, sl);
}
