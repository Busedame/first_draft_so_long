/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:00:56 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 17:12:34 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	run_game(t_game **sl)
{
	mlx_hook((*sl)->mlx_win, 2, 1L << 0, key_hook, *sl);
	mlx_hook((*sl)->mlx_win, 17, 0, close_hook_cross, *sl);
	mlx_loop((*sl)->mlx);
}
