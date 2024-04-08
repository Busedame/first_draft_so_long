/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:53:18 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/08 17:01:52 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_array_length(t_path *path)
{
	int	s;

	s = 0;
	while (path->original_map[s])
		s++;
	return (s);
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
}

void	init_map_in_window(t_img *imgs, t_path *path, void *mlx, void *mlx_win)
{
	void	*img;
	int		size;
	int		x;
	int		y;
	int		plc_x;
	int		plc_y;

	size = 65;
	plc_y = 0;
	x = 0;
	y = 0;
	while (path->original_map[y])
	{
		x = 0;
		plc_x = 0;
		while (path->original_map[y][x])
		{
			if (path->original_map[y][x] == '1')
			{
				img = mlx_xpm_file_to_image(mlx, imgs->wall, &size, &size);
				mlx_put_image_to_window(mlx, mlx_win, img, plc_x, plc_y);
			}
			else if (path->original_map[y][x] == 'P')
			{
				img = mlx_xpm_file_to_image(mlx, imgs->me, &size, &size);
				mlx_put_image_to_window(mlx, mlx_win, img, plc_x, plc_y);
			}
			else if (path->original_map[y][x] == 'C')
			{
				img = mlx_xpm_file_to_image(mlx, imgs->food, &size, &size);
				mlx_put_image_to_window(mlx, mlx_win, img, plc_x, plc_y);
			}
			else if (path->original_map[y][x] == 'E')
			{
				img = mlx_xpm_file_to_image(mlx, imgs->bed, &size, &size);
				mlx_put_image_to_window(mlx, mlx_win, img, plc_x, plc_y);
			}
			x++;
			plc_x += size;
		}
		y++;
		plc_y += size;
	}
}

void	init_struct(t_game *so_long, t_path *path)
{
	so_long = NULL;
	so_long = malloc(sizeof(t_game));
	if (!so_long)
		init_window_errors(1, &path, NULL);
	so_long->mlx = NULL;
	so_long->mlx_win = NULL;
	so_long->p_x = 0;
	so_long->p_y = 0;
	so_long->x = 0;
	so_long->y = 0;
}

void	find_player(t_game *so_long, t_path *path)
{
	int		x;
	int		y;
	bool	p_found;

	y = 0;
	while (path->original_map[y])
	{
		x = 0;
		so_long->p_x = 0;
		while (path->original_map[y][x])
		{
			if (path->original_map[y][x] == 'P')
			{
				p_found = true;
				break ;
			}
			so_long->p_x += 65;
			x++;
		}
		if (p_found == true)
			break ;
		so_long->p_y += 65;
		y++;
	}
	so_long->x = so_long->p_x / 65;
	so_long->y = so_long->p_y / 65;
}

void	move_player(t_game *so_long, int dir)
{
	void	*img;
	int		size;
	int		rm_p;

	size = 65;
	if (dir == 1)
	{
		rm_p = so_long->p_y + 65;
		img = mlx_xpm_file_to_image(so_long->mlx, "textures/back.xpm", &size, &size);
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, img, so_long->p_x, rm_p);
	}
	if (dir == 2)
	{
		rm_p = so_long->p_y - 65;
		img = mlx_xpm_file_to_image(so_long->mlx, "textures/back.xpm", &size, &size);
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, img, so_long->p_x, rm_p);
	}
	if (dir == 3)
	{
		rm_p = so_long->p_x + 65;
		img = mlx_xpm_file_to_image(so_long->mlx, "textures/back.xpm", &size, &size);
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, img, rm_p, so_long->p_y);
	}
	if (dir == 4)
	{
		rm_p = so_long->p_x - 65;
		img = mlx_xpm_file_to_image(so_long->mlx, "textures/back.xpm", &size, &size);
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, img, rm_p, so_long->p_y);
	}
	img = mlx_xpm_file_to_image(so_long->mlx, so_long->imgs->me, &size, &size);
	mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, img, so_long->p_x, so_long->p_y);
}

void	is_finished(t_game *so_long)
{
	int		x;
	int		y;
	bool	finish;

	y = 0;
	finish = true;
	if (so_long->path->original_map[so_long->y][so_long->x] == 'C')
		so_long->path->original_map[so_long->y][so_long->x] = '0';
	if (so_long->path->original_map[so_long->y][so_long->x] == 'E')
	{
		while (so_long->path->original_map[y])
		{
			x = 0;
			while (so_long->path->original_map[y][x])
			{
				if (so_long->path->original_map[y][x] == 'C')
				{
					finish = false;
					break ;
				}
				x++;
			}
			if (finish == false)
				return ;
			y++;
		}
		// destroy more stuff (mlx_destroy_display, free_images) -> then destroy window
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
		exit(0);
	}
}

int	key_hook(int keycode, t_game *so_long)
{
	int		dir;

	dir = 0;
	init_images(&so_long->imgs, &so_long->path);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
		exit(0);
	}
	else if (keycode == KEY_UP)
	{
		if (so_long->path->original_map[so_long->y - 1][so_long->x] != '1')
		{
			so_long->p_y -= 65;
			so_long->y--;
			dir = 1;
		}
	}
	else if (keycode == KEY_DOWN)
	{
		if (so_long->path->original_map[so_long->y + 1][so_long->x] != '1')
		{
			so_long->p_y += 65;
			so_long->y++;
			dir = 2;
		}
	}
	else if (keycode == KEY_LEFT)
	{
		if (so_long->path->original_map[so_long->y][so_long->x - 1] != '1')
		{
			so_long->p_x -= 65;
			so_long->x--;
			dir = 3;
		}
	}
	else if (keycode == KEY_RIGHT)
	{
		if (so_long->path->original_map[so_long->y][so_long->x + 1] != '1')
		{
			so_long->p_x += 65;
			so_long->x++;
			dir = 4;
		}
	}
	move_player(so_long, dir);
	is_finished(so_long);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	so_long;
	t_path	*path;
	t_img	*imgs;
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;

	if (argc != 2)
	{
		errno = EINVAL;
		perror("Error\nNeed path to map");
		return (1);
	}
	check_map(argv);
	so_long.path = check_map_path(argv);
	init_struct(&so_long, path);
	so_long.mlx = mlx_init();
	height = 65 * count_array_length(so_long.path);
	width = 65 * ft_strlen(so_long.path->original_map[0]) - 65;
	so_long.mlx_win = mlx_new_window(so_long.mlx, width, height, "so_long");
	init_images(&imgs, &so_long.path);
	init_map_in_window(imgs, so_long.path, so_long.mlx, so_long.mlx_win);
	find_player(&so_long, so_long.path);
	mlx_hook(so_long.mlx_win, 2, 1L << 0, key_hook, &so_long);
	mlx_loop(so_long.mlx);
}

// Add char *envp[] as argument to main.
// cc -g *.c get_next_line/*.c ft_printf/*.c validate_map/*.c validate_map/*/*.c minilibx-linux/libmlx_Linux.a -lX11 -lXext -lbsd -lm
// 