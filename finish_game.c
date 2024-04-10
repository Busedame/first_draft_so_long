/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:58:48 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/10 12:59:07 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_finished(t_game *sl)
{
	int		x;
	int		y;
	bool	finish;

	y = 0;
	finish = true;
	if (sl->path->original_map[sl->y][sl->x] == 'C')
		sl->path->original_map[sl->y][sl->x] = '0';
	if (sl->path->original_map[sl->y][sl->x] == 'E')
	{
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
				return ;
			y++;
		}
		// destroy more stuff (mlx_destroy_display, free_images) -> then destroy window
		mlx_destroy_window(sl->mlx, sl->mlx_win);
		exit(0);
	}
}
