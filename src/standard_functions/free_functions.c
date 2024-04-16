/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:28:40 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 18:39:32 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_all(t_game **sl)
{
	if ((*sl)->window_start)
		mlx_destroy_window((*sl)->mlx, (*sl)->mlx_win);
	if ((*sl)->display_start)
		mlx_destroy_display((*sl)->mlx);
	if ((*sl))
	{
		if ((*sl)->imgs)
			free_imgs((*sl)->imgs);
		if ((*sl)->path)
			free_path((*sl)->path);
		if ((*sl)->mlx)
			free((*sl)->mlx);
		free((*sl));
		(*sl) = NULL;
	}
}

void	free_imgs(t_img *imgs)
{
	if (imgs)
	{
		if (imgs->bed)
			ft_free(imgs->bed);
		if (imgs->shop)
			ft_free(imgs->shop);
		if (imgs->food)
			ft_free(imgs->food);
		if (imgs->me)
			ft_free(imgs->me);
		if (imgs->wall)
			ft_free(imgs->wall);
		if (imgs->back)
			ft_free(imgs->back);
		if (imgs->exit)
			ft_free(imgs->exit);
		if (imgs->win)
			ft_free(imgs->win);
		free(imgs);
	}
}

void	free_path(t_path *path)
{
	if (path)
	{
		if (path->original_map)
			ft_freearray(path->original_map);
		if (path->flood_map)
			ft_freearray(path->flood_map);
		free(path);
	}
}

void	free_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	ft_freearray(char **arr)
{
	int	crstr;
	int	max;

	crstr = 0;
	max = 0;
	while (arr[crstr])
	{
		crstr++;
		max++;
	}
	crstr = 0;
	while (crstr < max)
	{
		free(arr[crstr]);
		arr[crstr] = NULL;
		crstr++;
	}
	free(arr);
	arr = NULL;
	return (0);
}
