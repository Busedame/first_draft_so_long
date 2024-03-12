/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:28:15 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/12 19:36:21 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_errors(int error_code)
{
	if (error_code == 1)
		perror("ERROR: Failed to open map-file");
	if (error_code == 2)
	{
		errno = EINVAL;
		perror("ERROR: Invalid file-type");
	}
	if (error_code == 3)
	{
		errno = EINVAL;
		perror("ERROR: Not a rectangular map");
	}
	if (error_code == 4)
		perror("ERROR: Close function failed in check_map.c");
	if (error_code == 5)
		perror("ERROR: Invalid map. Make sure there is only one P, E and C");
	exit(1);
}
