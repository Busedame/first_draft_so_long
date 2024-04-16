/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_elements_in_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:52:47 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 18:44:29 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	build_background(t_game *sl, void *mlx, void *mlx_win, int size)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, sl->imgs->back, &size, &size);
	if (!img)
		game_errors(3, &sl);
	if (mlx_put_image_to_window(mlx, mlx_win, img, sl->plc_x, sl->plc_y) == -1)
		image_error(img, &sl);
	mlx_destroy_image(mlx, img);
}

void	build_exit(t_game *sl, void *mlx, void *mlx_win, int size)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, sl->imgs->bed, &size, &size);
	if (!img)
		game_errors(3, &sl);
	if (mlx_put_image_to_window(mlx, mlx_win, img, sl->plc_x, sl->plc_y) == -1)
		image_error(img, &sl);
	mlx_destroy_image(mlx, img);
}

void	build_collectible(t_game *sl, void *mlx, void *mlx_win, int size)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, sl->imgs->food, &size, &size);
	if (!img)
		game_errors(3, &sl);
	if (mlx_put_image_to_window(mlx, mlx_win, img, sl->plc_x, sl->plc_y) == -1)
		image_error(img, &sl);
	mlx_destroy_image(mlx, img);
}

void	build_player(t_game *sl, void *mlx, void *mlx_win, int size)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, sl->imgs->me, &size, &size);
	if (!img)
		game_errors(3, &sl);
	if (mlx_put_image_to_window(mlx, mlx_win, img, sl->plc_x, sl->plc_y) == -1)
		image_error(img, &sl);
	mlx_destroy_image(mlx, img);
}

void	build_wall(t_game *sl, void *mlx, void *mlx_win, int size)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, sl->imgs->wall, &size, &size);
	if (!img)
		game_errors(3, &sl);
	if (mlx_put_image_to_window(mlx, mlx_win, img, sl->plc_x, sl->plc_y) == -1)
		image_error(img, &sl);
	mlx_destroy_image(mlx, img);
}
