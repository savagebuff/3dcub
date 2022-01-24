/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:48:54 by choney            #+#    #+#             */
/*   Updated: 2021/04/21 18:14:40 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = destination;
	while (i < len)
	{
		dest[i] = c;
		i++;
	}
	return (dest);
}
