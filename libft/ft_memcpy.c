/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:50:05 by choney            #+#    #+#             */
/*   Updated: 2021/04/21 18:23:25 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t len)
{
	size_t	i;
	char	*dst;
	char	*src;

	i = 0;
	dst = destination;
	src = (char *)source;
	if (!source && !destination)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
