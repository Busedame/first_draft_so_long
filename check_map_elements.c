/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:23:32 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/12 20:28:20 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_exit(char	*line)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (line[x] != '\n')
	{
		if (line[x] == 'E')
			count++;
		x++;
	}
	return (count);
}

static int	check_position(char	*line)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (line[x] != '\n')
	{
		if (line[x] == 'P')
			count++;
		x++;
	}
	return (count);
}

static int	check_collectibles(char	*line)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (line[x] != '\n')
	{
		if (line[x] == 'C')
			count++;
		x++;
	}
	return (count);
}

static int	check_first_or_last_line(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\n' && line[x] != '\0')
	{
		if (line[x] != '1')
		{
			free(line);
			return (-1);
		}
		x++;
	}
	return (0);
}

static int	check_walls(char *line)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(line) - 2;
	if (line[start] != '1')
		return (-1);
	if (line[end] != '1')
		return (-1);
	return (0);
}

int	check_map_elements(int map)
{
	char	*line;
	int		count_e;
	int		count_p;
	int		count_c;

	line = get_next_line(map);
	if (!line)
		return (-1);
	count_e = 0;
	count_p = 0;
	count_c = 0;
	if (check_first_or_last_line(line) == -1)
		return (finish_read(map));
	free(line);
	line = get_next_line(map);
	while (line)
	{
		if (ft_strchr_index(line, '\n') == -1)
		{
			if (check_first_or_last_line(line) == -1)
				return (finish_read(map));
			break ;
		}
		if (check_walls(line) == -1)
		{
			free(line);
			return (finish_read(map));
		}
		count_e += check_exit(line);
		count_p += check_position(line);
		count_c += check_collectibles(line);
		free(line);
		line = get_next_line(map);
	}
	if (count_e == 0 || count_p == 0 || count_c == 0
		|| count_e > 1 || count_p > 1)
		return (finish_read(map));
	if (line)
		free(line);
	return (0);
}
