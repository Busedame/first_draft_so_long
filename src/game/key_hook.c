/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:20:46 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/15 16:28:54 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	right_key(t_game *sl)
{
	int	dir;

	dir = 0;
	if (sl->path->original_map[sl->y][sl->x + 1] != '1')
	{
		sl->p_x += 65;
		sl->x++;
		dir = 4;
	}
	return (dir);
}

int	left_key(t_game *sl)
{
	int	dir;

	dir = 0;
	if (sl->path->original_map[sl->y][sl->x - 1] != '1')
	{
		sl->p_x -= 65;
		sl->x--;
		dir = 3;
	}
	return (dir);
}

int	down_key(t_game *sl)
{
	int	dir;

	dir = 0;
	if (sl->path->original_map[sl->y + 1][sl->x] != '1')
	{
		sl->p_y += 65;
		sl->y++;
		dir = 2;
	}
	return (dir);
}

int	up_key(t_game *sl)
{
	int	dir;

	dir = 0;
	if (sl->path->original_map[sl->y - 1][sl->x] != '1')
	{
		sl->p_y -= 65;
		sl->y--;
		dir = 1;
	}
	return (dir);
}

int	key_hook(int keycode, t_game *sl)
{
	int			dir;
	static int	moves;

	dir = 0;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(sl->mlx, sl->mlx_win);
		mlx_destroy_display(sl->mlx);
		free_all(&sl);
		exit(0);
	}
	else if (keycode == KEY_UP || keycode == W_UP)
		dir = up_key(sl);
	else if (keycode == KEY_DOWN || keycode == S_DOWN)
		dir = down_key(sl);
	else if (keycode == KEY_LEFT || keycode == A_LEFT)
		dir = left_key(sl);
	else if (keycode == KEY_RIGHT || keycode == D_RIGHT)
		dir = right_key(sl);
	else
		return (1);
	move_player(sl, dir);
	ft_printf("Number of movements: %d\n", ++moves);
	is_finished(sl);
	return (0);
}
