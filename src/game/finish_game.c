/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:58:48 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 18:34:28 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	put_exit(t_game *sl, int size, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->exit, &size, &size);
	if (!img)
		game_errors(3, &sl);
	if (mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, x * 65, \
	y * 65) == -1)
		image_error(img, &sl);
	mlx_destroy_image(sl->mlx, img);
	return (0);
}

int	find_exit(t_game *sl)
{
	int		x;
	int		y;
	bool	e_found;
	int		size;

	y = 0;
	size = 65;
	e_found = false;
	while (sl->path->original_map[y])
	{
		x = 0;
		while (sl->path->original_map[y][x])
		{
			if (sl->path->original_map[y][x] == 'E')
			{
				e_found = true;
				break ;
			}
			x++;
		}
		if (e_found == true)
			return (put_exit(sl, size, x, y));
		y++;
	}
	return (0);
}

int	check_finish_collectibles(t_game *sl)
{
	int		x;
	int		y;
	bool	finish;

	y = 0;
	finish = true;
	while (sl->path->original_map[y])
	{
		x = 0;
		while (sl->path->original_map[y][x])
		{
			if (sl->path->original_map[y][x] == 'C')
			{
				finish = false;
				break ;
			}
			x++;
		}
		if (finish == false)
			return (0);
		y++;
	}
	return (1);
}

void	you_won_end_img(t_game *sl)
{
	void	*img;
	int		size;

	size = 130;
	sl->x = (sl->win_width - size) / 2;
	sl->y = (sl->win_height - size) / 2;
	img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->win, &size, &size);
	if (!img)
		game_errors(3, &sl);
	if (mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, sl->x, sl->y) == -1)
		image_error(img, &sl);
	mlx_destroy_image(sl->mlx, img);
}

void	is_finished(t_game *sl)
{
	if (sl->path->original_map[sl->y][sl->x] == 'C' 
		|| sl->path->original_map[sl->y][sl->x] == 'P')
		sl->path->original_map[sl->y][sl->x] = '0';
	if (check_finish_collectibles(sl))
		find_exit(sl);
	if (sl->path->original_map[sl->y][sl->x] == 'E' &&
		check_finish_collectibles(sl))
	{
		you_won_end_img(sl);
		ft_printf("You won!!\n");
		sl->game_ended = true;
	}
}
