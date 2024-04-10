/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:01 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/10 13:23:40 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_array_length(t_path *path)
{
	int	s;

	s = 0;
	while (path->original_map[s])
		s++;
	return (s);
}

void	init_map_in_window(t_img *imgs, t_path *path, void *mlx, void *mlx_win)
{
	void	*img;
	int		size;
	int		x;
	int		y;
	int		plc_x;
	int		plc_y;

	size = 65;
	plc_y = 0;
	x = 0;
	y = 0;
	while (path->original_map[y])
	{
		x = 0;
		plc_x = 0;
		while (path->original_map[y][x])
		{
			if (path->original_map[y][x] == '1')
			{
				img = mlx_xpm_file_to_image(mlx, imgs->wall, &size, &size);
				mlx_put_image_to_window(mlx, mlx_win, img, plc_x, plc_y);
			}
			else if (path->original_map[y][x] == 'P')
			{
				img = mlx_xpm_file_to_image(mlx, imgs->me, &size, &size);
				mlx_put_image_to_window(mlx, mlx_win, img, plc_x, plc_y);
			}
			else if (path->original_map[y][x] == 'C')
			{
				img = mlx_xpm_file_to_image(mlx, imgs->food, &size, &size);
				mlx_put_image_to_window(mlx, mlx_win, img, plc_x, plc_y);
			}
			else if (path->original_map[y][x] == 'E')
			{
				img = mlx_xpm_file_to_image(mlx, imgs->bed, &size, &size);
				mlx_put_image_to_window(mlx, mlx_win, img, plc_x, plc_y);
			}
			x++;
			plc_x += size;
		}
		y++;
		plc_y += size;
	}
}

void	init_struct(t_game *sl, t_path *path)
{
	sl = NULL;
	sl = malloc(sizeof(t_game));
	if (!sl)
		init_window_errors(1, &path, NULL);
	sl->mlx = NULL;
	sl->mlx_win = NULL;
	sl->p_x = 0;
	sl->p_y = 0;
	sl->x = 0;
	sl->y = 0;
}

void	find_player(t_game *sl, t_path *path)
{
	int		x;
	int		y;
	bool	p_found;

	y = 0;
	while (path->original_map[y])
	{
		x = 0;
		sl->p_x = 0;
		while (path->original_map[y][x])
		{
			if (path->original_map[y][x] == 'P')
			{
				p_found = true;
				break ;
			}
			sl->p_x += 65;
			x++;
		}
		if (p_found == true)
			break ;
		sl->p_y += 65;
		y++;
	}
	sl->x = sl->p_x / 65;
	sl->y = sl->p_y / 65;
}
