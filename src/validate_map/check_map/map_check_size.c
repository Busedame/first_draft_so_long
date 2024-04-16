/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:26:14 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/15 13:18:35 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

static char	*init_count_each_line(char *line, int map)
{
	line = get_next_line(map);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free_line(line);
		return (NULL);
	}
	if (ft_strchr_index(line, '\n') == -1)
	{
		free_line(line);
		return (NULL);
	}
	return (line);
}

static char	*line_iteration(char *line, int map)
{
	free_line(line);
	line = get_next_line(map);
	if (!line)
		return (NULL);
	return (line);
}

static int	check_curr_count(char *line)
{
	int	curr_count;

	curr_count = 0;
	if (ft_strchr_index(line, '\n') == -1)
		curr_count = ft_strlen(line);
	else
		curr_count = ft_strlen(line) - 1;
	return (curr_count);
}

int	count_each_line(int map)
{
	int		count;
	int		curr_count;
	char	*line;

	line = NULL;
	line = init_count_each_line(line, map);
	if (!line)
		return (-1);
	count = ft_strlen(line) - 1;
	while (1)
	{
		curr_count = 0;
		line = line_iteration(line, map);
		if (!line)
			break ;
		curr_count = check_curr_count(line);
		if ((curr_count != count && line[0] != '\n') 
			|| (ft_strchr_index(line, '\n') == -1))
			break ;
	}
	if (count != curr_count && line)
		return (finish_read(map, line));
	if (line)
		free_line(line);
	return (0);
}
