/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:53:18 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/10 12:44:44 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	sl;
	t_path	*path;
	int		width;
	int		height;

	if (argc != 2)
	{
		errno = EINVAL;
		perror("Error\nNeed path to map");
		return (1);
	}
	check_map(argv);
	sl.path = check_map_path(argv);
	init_struct(&sl, path);
	sl.mlx = mlx_init();
	height = 65 * count_array_length(sl.path);
	width = 65 * ft_strlen(sl.path->original_map[0]) - 65;
	sl.mlx_win = mlx_new_window(sl.mlx, width, height, "so_long");
	init_images(&sl.imgs, &sl.path);
	init_map_in_window(sl.imgs, sl.path, sl.mlx, sl.mlx_win);
	find_player(&sl, sl.path);
	mlx_hook(sl.mlx_win, 2, 1L << 0, key_hook, &sl);
	mlx_loop(sl.mlx);
}

// Add char *envp[] as argument to main.
// cc -g *.c get_next_line/*.c ft_printf/*.c validate_map/*.c validate_map/*/*.c minilibx-linux/libmlx_Linux.a -lX11 -lXext -lbsd -lm
//