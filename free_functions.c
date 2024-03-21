/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:28:40 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/21 18:18:38 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_game *so_long)
{
	if (so_long)
		free(so_long);
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
