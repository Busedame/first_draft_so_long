/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_array_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:45:15 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/16 16:45:28 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_array_length(t_path *path)
{
	int	s;

	s = 0;
	while (path->original_map[s] && path->original_map[s][0] != '\n')
		s++;
	return (s);
}
