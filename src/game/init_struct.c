/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:27 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 17:54:29 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_struct(t_game **sl)
{
	(*sl) = malloc(sizeof(t_game));
	if (!(*sl))
		game_errors(1, sl);
	(*sl)->path = NULL;
	(*sl)->imgs = NULL;
	(*sl)->mlx = NULL;
	(*sl)->mlx_win = NULL;
	(*sl)->p_x = 0;
	(*sl)->p_y = 0;
	(*sl)->x = 0;
	(*sl)->y = 0;
	(*sl)->win_height = 0;
	(*sl)->win_width = 0;
	(*sl)->display_start = false;
	(*sl)->window_start = false;
	(*sl)->game_ended = false;
	(*sl)->moves = 0;
	(*sl)->plc_x = 0;
	(*sl)->plc_y = 0;
}
