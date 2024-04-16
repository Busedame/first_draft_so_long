/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:38:40 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 18:42:03 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	game_errors(int error_code, t_game **sl)
{
	if (sl)
		free_all(sl);
	if (error_code == 0)
		perror("Error\nDisplay initialization failed");
	if (error_code == 1)
		perror("Error\nMemory allocation failed");
	if (error_code == 2)
		perror("Error\nWindow initialization failed");
	if (error_code == 3)
		perror("Error\nImage initialization failed");
	exit(1);
}

void	image_error(void *img, t_game **sl)
{
	mlx_destroy_image((*sl)->mlx, img);
	if (sl)
		free_all(sl);
	perror("Error\nFailed to put image to window");
	exit(1);
}
