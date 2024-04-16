/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_in_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:49:06 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 17:29:06 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_map_in_window(t_game *sl, void *mlx, void *mlx_win)
{
	int		size;
	int		y;

	size = 65;
	sl->plc_y = 0;
	y = 0;
	while (sl->path->original_map[y])
	{
		build_map_in_window(sl, mlx, mlx_win, y);
		y++;
		sl->plc_y += size;
	}
}
