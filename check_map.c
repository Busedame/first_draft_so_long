/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:27:24 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/12 19:36:51 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	map;

	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_errors(1);
	if (check_file_type(argv[1]) == -1)
		map_errors(2);
	if (count_each_line(map) == -1)
	{
		close(map);
		map_errors(3);
	}
	if (close(map) == -1)
		map_errors(4);
	map = open(argv[1], O_RDONLY);
	if (map == -1)
		map_errors(1);
	if (check_map_elements(map) == -1)
	{
		close(map);
		map_errors(5);
	}
	if (close(map) == -1)
		map_errors(4);
}
