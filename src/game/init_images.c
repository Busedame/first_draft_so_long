/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:41 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/13 19:09:24 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	set_images(t_game *sl)
{
	sl->imgs->me = ft_strdup("textures/me.xpm");
	if (!sl->imgs->me)
		init_window_errors(1, &sl);
	sl->imgs->food = ft_strdup("textures/food.xpm");
	if (!sl->imgs->food)
		init_window_errors(1, &sl);
	sl->imgs->shop = ft_strdup("textures/shop.xpm");
	if (!sl->imgs->shop)
		init_window_errors(1, &sl);
	sl->imgs->bed = ft_strdup("textures/bed.xpm");
	if (!sl->imgs->bed)
		init_window_errors(1, &sl);
	sl->imgs->wall = ft_strdup("textures/wall.xpm");
	if (!sl->imgs->wall)
		init_window_errors(1, &sl);
	sl->imgs->back = ft_strdup("textures/back.xpm");
	if (!sl->imgs->back)
		init_window_errors(1, &sl);
	sl->imgs->exit = ft_strdup("textures/exit.xpm");
	if (!sl->imgs->exit)
		init_window_errors(1, &sl);
	sl->imgs->win = ft_strdup("textures/win.xpm");
	if (!sl->imgs->win)
		init_window_errors(1, &sl);
}

void	init_images(t_game *sl)
{
	sl->imgs = malloc(sizeof(t_img));
	if (!sl->imgs)
		init_window_errors(1, &sl);
	sl->imgs->me = NULL;
	sl->imgs->food = NULL;
	sl->imgs->shop = NULL;
	sl->imgs->bed = NULL;
	sl->imgs->wall = NULL;
	sl->imgs->back = NULL;
	sl->imgs->exit = NULL;
	sl->imgs->win = NULL;
	set_images(sl);
}
