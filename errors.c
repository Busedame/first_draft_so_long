/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:38:40 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/04 17:46:01 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window_errors(int error_code, t_path **path, t_img **imgs)
{
	if (error_code == 1)
		perror("Error\nMemory allocation failed");
	if ((*path))
		free_path((*path));
	if ((*imgs))
		free_imgs((*imgs));
	exit(1);
}
