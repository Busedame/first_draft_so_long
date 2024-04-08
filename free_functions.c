/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:28:40 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/04 17:40:20 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *so_long)
{
	if (so_long)
		free(so_long);
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

void	free_floodmap(t_path *path)
{
	if (path->flood_map)
		ft_freearray(path->flood_map);
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
