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

#include "../inc/so_long.h"

void	init_game(t_game **sl)
{
	int		width;
	int		height;

	(*sl)->mlx = mlx_init();
	(*sl)->win_height = 65 * count_array_length((*sl)->path);
	(*sl)->win_width = 65 * ft_strlen((*sl)->path->original_map[0]) - 65;
	(*sl)->mlx_win = mlx_new_window((*sl)->mlx, (*sl)->win_width, \
	(*sl)->win_height, "so_long");
	init_images(*sl);
	init_map_in_window(*sl, (*sl)->mlx, (*sl)->mlx_win);
	find_player(*sl);
	mlx_hook((*sl)->mlx_win, 2, 1L << 0, key_hook, *sl);
	mlx_hook((*sl)->mlx_win, 17, 0, close_hook, *sl);
	mlx_loop((*sl)->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	*sl;

	if (argc != 2)
	{
		errno = EINVAL;
		perror("Error\nNeed path to map");
		return (1);
	}
	sl = NULL;
	init_struct(&sl);
	check_map(argv, &sl);
	check_map_path(argv, &sl);
	init_game(&sl);
}
