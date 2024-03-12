/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:53:18 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/12 19:37:08 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*so_long;

	so_long = NULL;
	if (argc != 2)
	{
		errno = EINVAL;
		return (1);
	}
	check_map(argv);
}
