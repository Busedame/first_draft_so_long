/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:33:34 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 17:53:57 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	find_player(t_game *sl)
{
	bool	p_found;

	sl->y = 0;
	p_found = false;
	while (sl->path->original_map[sl->y][0] != '\n' 
		&& sl->path->original_map[sl->y])
	{
		sl->x = 0;
		sl->p_x = 0;
		while (sl->path->original_map[sl->y][sl->x])
		{
			if (sl->path->original_map[sl->y][sl->x] == 'P')
			{
				p_found = true;
				break ;
			}
			sl->p_x += 65;
			sl->x++;
		}
		if (p_found == true)
			break ;
		sl->p_y += 65;
		sl->y++;
	}
}

void	init_game(t_game **sl)
{
	(*sl)->mlx = mlx_init();
	if (!(*sl)->mlx)
		game_errors(0, sl);
	(*sl)->display_start = true;
	(*sl)->win_height = 65 * count_array_length((*sl)->path);
	(*sl)->win_width = 65 * ft_strlen((*sl)->path->original_map[0]) - 65;
	(*sl)->mlx_win = mlx_new_window((*sl)->mlx, (*sl)->win_width, \
	(*sl)->win_height, "so_long");
	if (!(*sl)->mlx_win)
		game_errors(2, sl);
	(*sl)->window_start = true;
	init_images(*sl);
	init_map_in_window(*sl, (*sl)->mlx, (*sl)->mlx_win);
	find_player(*sl);
}
