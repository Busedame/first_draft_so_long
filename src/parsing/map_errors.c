/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:28:15 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/15 13:59:05 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	map_path_errors(int error_code, t_game **sl)
{
	if (error_code == 1)
		perror("Error\nFailed to open map-file");
	if (error_code == 2)
		perror("Error\nMemory allocation failed");
	if (error_code == 3)
		perror("Error\nFailed to close map-file");
	if (error_code == 4)
	{
		errno = EINVAL;
		perror("Error\nNo valid path");
	}
	if (sl)
		free_all(sl);
	exit(1);
}

void	map_errors(int error_code, t_count *counter, t_game **sl)
{
	if (error_code == 1)
		perror("Error\nFailed to open map-file");
	if (error_code == 2)
	{
		errno = EINVAL;
		perror("Error\nInvalid file-type");
	}
	if (error_code == 3)
	{
		errno = EINVAL;
		perror("Error\nInvalid map");
	}
	if (error_code == 4)
		perror("Error\nClose function failed in check_map.c");
	if (error_code == 5)
		perror("Error\nMemory allocation failed");
	if (counter)
		free(counter);
	if (sl)
		free_all(sl);
	exit(1);
}
