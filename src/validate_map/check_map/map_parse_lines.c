/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:23:32 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/19 14:08:57 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

static int	check_first_or_last_line(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\n' && line[x] != '\r' && line[x] != '\0')
	{
		if (line[x] != '1')
			return (-1);
		x++;
	}
	return (0);
}

static int	parse_line(t_count *counter, char *line, int map)
{
	while (line)
	{
		counter->line_count++;
		if (ft_strchr_index(line, '\n') == -1)
		{
			if (check_first_or_last_line(line) == -1)
				return (finish_read(map, &line));
		}
		if (check_invalid_chars(line) == -1)
			return (finish_read(map, &line));
		if (check_walls(line) == -1)
			return (finish_read(map, &line));
		check_exit(line, counter);
		check_position(line, counter);
		check_collectibles(line, counter);
		free(line);
		line = get_next_line(map);
	}
	if (line)
		free(line);
	return (0);
}

int	check_map_elements(int map, t_count *counter)
{
	char	*line;

	line = get_next_line(map);
	if (!line)
		return (-1);
	counter->line_count = 1;
	counter->count_e = 0;
	counter->count_p = 0;
	counter->count_c = 0;
	if (check_first_or_last_line(line) == -1)
		return (finish_read(map, &line));
	free_line(line);
	line = get_next_line(map);
	if (parse_line(counter, line, map) == -1)
		return (-1);
	if (counter->count_e == 0 || counter->count_p == 0 || counter->count_c == 0
		|| counter->count_e > 1 || counter->count_p > 1 
		|| counter->line_count < 3)
		return (-1);
	free(counter);
	return (0);
}
