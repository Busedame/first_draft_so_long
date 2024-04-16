/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_in_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:23:01 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 16:53:06 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	build_map_in_window(t_game *sl, void *mlx, void *mlx_win, int y)
{
	int	x;
	int	size;

	x = 0;
	sl->plc_x = 0;
	size = 65;
	while (sl->path->original_map[y][x])
	{
		if (sl->path->original_map[y][x] == '1')
			build_wall(sl, mlx, mlx_win, size);
		else if (sl->path->original_map[y][x] == 'P')
			build_player(sl, mlx, mlx_win, size);
		else if (sl->path->original_map[y][x] == 'C')
			build_collectible(sl, mlx, mlx_win, size);
		else if (sl->path->original_map[y][x] == 'E')
			build_exit(sl, mlx, mlx_win, size);
		else if (sl->path->original_map[y][x] != '\n')
			build_background(sl, mlx, mlx_win, size);
		x++;
		sl->plc_x += size;
	}
}
