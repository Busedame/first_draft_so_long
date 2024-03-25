/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:53:18 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/25 16:25:49 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		next_line;
	int		line_thickness;
	int		space;

	next_line = 250;
	line_thickness = 20;
	space = 250;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = color;
			x++;
		}
		y++;
	}
	y = 0;
	while (y < line_thickness)
	{
		x = 0;
		while (x < 1920)
		{
			dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
			*(unsigned int *)dst = 0x00000000;
			x++;
		}
		y++;
	}
	y = next_line;
	while (y < 810)
	{
		while (y < next_line + line_thickness)
		{
			x = 0;
			while (x < 1920)
			{
				dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
				*(unsigned int *)dst = 0x00000000;
				x++;
			}
			y++;
		}
		y += space;
		next_line = y;
	}
}

int	main(int argc, char *argv[])
{
	t_game	*so_long;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	*tmp_img;

	so_long = NULL;
	if (argc != 2)
	{
		errno = EINVAL;
		perror("Error\nNeed path to map");
		return (1);
	}
	check_map(argv);
	check_map_path(argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	tmp_img = &img;
	my_mlx_pixel_put(tmp_img, 0, 0, 0x00FFFF00);
	mlx_clear_window(mlx, mlx_win);
	img = *tmp_img;
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

// Add char *envp[] as argument to main.
// cc *.c get_next_line/*.c ft_printf/*.c validate_map/*.c validate_map/*/*.c minilibx-linux/libmlx_Linux.a -lX11 -lXext -lbsd -lm