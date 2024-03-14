/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:26:14 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/14 16:23:59 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*init_count_each_line(char *line, int map)
{
	line = get_next_line(map);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	if (ft_strchr_index(line, '\n') == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*line_iteration(char *line, int map)
{
	free(line);
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
			return (-1);
		curr_count = check_curr_count(line);
		if (curr_count != count || ft_strchr_index(line, '\n') == -1)
			break ;
	}
	free(line);
	if (count != curr_count)
		return (finish_read(map));
	return (0);
}
