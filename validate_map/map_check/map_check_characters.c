/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_characters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:57:40 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/21 18:37:19 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_exit(char	*line, t_count *counter)
{
	int	x;

	x = 0;
	while (line[x] != '\n')
	{
		if (line[x] == 'E')
			counter->count_e++;
		x++;
	}
}

void	check_position(char	*line, t_count *counter)
{
	int	x;

	x = 0;
	while (line[x] != '\n')
	{
		if (line[x] == 'P')
			counter->count_p++;
		x++;
	}
}

void	check_collectibles(char	*line, t_count *counter)
{
	int	x;

	x = 0;
	while (line[x] != '\n')
	{
		if (line[x] == 'C')
			counter->count_c++;
		x++;
	}
}

int	check_walls(char *line)
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

int	check_invalid_chars(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\n' && line[x] != '\0')
	{
		if (line[x] != '1' && line[x] != '0' && line[x] != 'C' && line[x] != 'E'
			&& line[x] != 'P')
		{
			free(line);
			return (-1);
		}
		x++;
	}
	return (0);
}
