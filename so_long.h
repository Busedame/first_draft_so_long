/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:51:43 by nholbroo          #+#    #+#             */
/*   Updated: 2024/03/12 20:01:47 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <errno.h>

typedef struct s_list
{
	int	tmp;
	int	tmp2;
}	t_list;

void	free_all(t_list *so_long);
void	map_errors(int error_code);
void	check_map(char *argv[]);
int		count_each_line(int map);
int		check_file_type(char *map_filename);
int		check_map_elements(int map);
int		finish_read(int map);

#endif