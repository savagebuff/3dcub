/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:25:42 by choney            #+#    #+#             */
/*   Updated: 2021/05/22 17:49:55 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		if (source[i] == (char)c)
		{
			destination[i] = source[i];
			return (destination + i + 1);
		}
		destination[i] = source[i];
		i++;
	}
	return (NULL);
}
