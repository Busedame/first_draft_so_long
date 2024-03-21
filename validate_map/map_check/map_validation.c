/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:24 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/21 18:37:04 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	finish_read(int map)
{
	char	*line;

	line = get_next_line(map);
	while (line)
	{
		free(line);
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

void	check_map(char *argv[])
{
	int		map;
	t_count	*counter;

	counter = malloc (sizeof(t_count));
	if (!counter)
		map_errors(5, counter);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_errors(1, counter);
	if (check_file_type(argv[1]) == -1)
		map_errors(2, counter);
	if (count_each_line(map) == -1)
	{
		close(map);
		map_errors(3, counter);
	}
	if (close(map) == -1)
		map_errors(4, counter);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_errors(1, counter);
	if (check_map_elements(map, counter) == -1)
		map_errors(6, counter);
	if (close(map) == -1)
		map_errors(4, counter);
}
