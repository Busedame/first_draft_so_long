/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:18:41 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/10 13:34:30 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_img **imgs, t_path **path)
{
	(*imgs)->me = ft_strdup("textures/me.xpm");
	if (!(*imgs)->me)
		init_window_errors(1, path, imgs);
	(*imgs)->food = ft_strdup("textures/food.xpm");
	if (!(*imgs)->food)
		init_window_errors(1, path, imgs);
	(*imgs)->shop = ft_strdup("textures/shop.xpm");
	if (!(*imgs)->shop)
		init_window_errors(1, path, imgs);
	(*imgs)->bed = ft_strdup("textures/bed.xpm");
	if (!(*imgs)->bed)
		init_window_errors(1, path, imgs);
	(*imgs)->wall = ft_strdup("textures/wall.xpm");
	if (!(*imgs)->wall)
		init_window_errors(1, path, imgs);
	(*imgs)->back = ft_strdup("textures/back.xpm");
	if (!(*imgs)->back)
		init_window_errors(1, path, imgs);
}

void	init_images(t_img **imgs, t_path **path)
{
	(*imgs) = malloc(sizeof(t_img));
	if (!(*imgs))
		init_window_errors(1, path, imgs);
	(*imgs)->me = NULL;
	(*imgs)->food = NULL;
	(*imgs)->shop = NULL;
	(*imgs)->bed = NULL;
	(*imgs)->wall = NULL;
	(*imgs)->back = NULL;
	set_images(imgs, path);
}
