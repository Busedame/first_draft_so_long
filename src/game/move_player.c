/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:24:50 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/13 18:08:53 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move_right(t_game *sl)
{
	void	*img;
	int		size;
	int		rm_p;
	int		old_x;

	size = 65;
	old_x = sl->x - 1;
	if (sl->path->original_map[sl->y][old_x] == 'E')
	{
		rm_p = sl->p_x - 65;
		img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->bed, &size, &size);
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, rm_p, sl->p_y);
	}
	else if (sl->path->original_map[sl->y][old_x] != '1')
	{
		rm_p = sl->p_x - 65;
		img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->back, &size, &size);
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, rm_p, sl->p_y);
	}
}

void	move_left(t_game *sl)
{
	void	*img;
	int		size;
	int		rm_p;
	int		old_x;

	size = 65;
	old_x = sl->x + 1;
	if (sl->path->original_map[sl->y][old_x] == 'E')
	{
		rm_p = sl->p_x + 65;
		img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->bed, &size, &size);
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, rm_p, sl->p_y);
	}
	else if (sl->path->original_map[sl->y][old_x] != '1')
	{
		rm_p = sl->p_x + 65;
		img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->back, &size, &size);
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, rm_p, sl->p_y);
	}
}

void	move_down(t_game *sl)
{
	void	*img;
	int		size;
	int		rm_p;
	int		old_y;

	size = 65;
	old_y = sl->y - 1;
	if (sl->path->original_map[old_y][sl->x] == 'E')
	{
		rm_p = sl->p_y - 65;
		img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->bed, &size, &size);
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, sl->p_x, rm_p);
	}
	else if (sl->path->original_map[old_y][sl->x] != '1')
	{
		rm_p = sl->p_y - 65;
		img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->back, &size, &size);
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, sl->p_x, rm_p);
	}
}

void	move_up(t_game *sl)
{
	void	*img;
	int		size;
	int		rm_p;
	int		old_y;

	size = 65;
	old_y = sl->y + 1;
	if (sl->path->original_map[old_y][sl->x] == 'E')
	{
		rm_p = sl->p_y + 65;
		img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->bed, &size, &size);
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, sl->p_x, rm_p);
	}
	else if (sl->path->original_map[old_y][sl->x] != '1')
	{
		rm_p = sl->p_y + 65;
		img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->back, &size, &size);
		mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, sl->p_x, rm_p);
	}
}

void	move_player(t_game *sl, int dir)
{
	void	*img;
	int		size;
	int		rm_p;

	size = 65;
	if (dir == 1)
		move_up(sl);
	if (dir == 2)
		move_down(sl);
	if (dir == 3)
		move_left(sl);
	if (dir == 4)
		move_right(sl);
	img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->me, &size, &size);
	mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, sl->p_x, sl->p_y);
}
