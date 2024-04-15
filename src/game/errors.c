/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:38:40 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/15 14:30:19 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_window_errors(int error_code, t_game **sl)
{
	if (sl)
		free_all(sl);
	if (error_code == 1)
		perror("Error\nMemory allocation failed");
	exit(1);
}
