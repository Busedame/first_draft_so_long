/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:58:48 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/13 18:12:08 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	find_exit(t_game *sl)
{
	int		x;
	int		y;
	bool	e_found;
	int		size;
	void	*img;

	y = 0;
	size = 65;
	while (sl->path->original_map[y])
	{
		x = 0;
		while (sl->path->original_map[y][x])
		{
			if (sl->path->original_map[y][x] == 'E')
			{
				e_found = true;
				break ;
			}
			x++;
		}
		if (e_found == true)
		{
			img = mlx_xpm_file_to_image(sl->mlx, sl->imgs->exit, &size, &size);
			mlx_put_image_to_window(sl->mlx, sl->mlx_win, img, x * 65, y * 65);
			return ;
		}
		y++;
	}
}

int	check_finish_collectibles(t_game *sl)
{
	int		x;
	int		y;
	bool	finish;

	y = 0;
	finish = true;
	while (sl->path->original_map[y])
	{
		x = 0;
		while (sl->path->original_map[y][x])
		{
			if (sl->path->original_map[y][x] == 'C')
			{
				finish = false;
				break ;
			}
			x++;
		}
		if (finish == false)
			return (0);
		y++;
	}
	return (1);
}

void	is_finished(t_game *sl)
{
	int		x;
	int		y;
	bool	finish;

	y = 0;
	finish = true;
	if (sl->path->original_map[sl->y][sl->x] == 'C' 
		|| sl->path->original_map[sl->y][sl->x] == 'P')
		sl->path->original_map[sl->y][sl->x] = '0';
	if (check_finish_collectibles(sl))
		find_exit(sl);
	if (sl->path->original_map[sl->y][sl->x] == 'E' &&
		check_finish_collectibles(sl))
	{
		ft_printf("You won!!\n");
		mlx_destroy_display(sl->mlx);
		mlx_destroy_window(sl->mlx, sl->mlx_win);
		free_all(sl);
		exit(0);
	}
}

int close_hook(void *param)
{
    void *mlx = param;

    mlx_destroy_display(mlx);
    exit(0);
}
