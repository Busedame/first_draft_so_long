/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:23:03 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/13 17:47:14 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "ft_printf.h"

char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);

int		ft_strchr_index(const char *s, int c);

void	*ft_free(void *ptr);

#endif