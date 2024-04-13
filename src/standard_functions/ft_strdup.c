/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:41:16 by nholbroo          #+#    #+#             */
/*   Updated: 2024/04/13 18:09:05 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	*ft_strdup(const char *s)
{
	char		*dup;
	int			i;
	size_t		len;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (s[len] != '\0')
		len++;
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
