/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:48:57 by choney            #+#    #+#             */
/*   Updated: 2021/04/22 14:04:08 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*mass;
	size_t			i;

	i = 0;
	mass = (unsigned char *)arr;
	while (i < n)
	{
		if (mass[i] == (unsigned char)c)
			return (mass + i);
		i++;
	}
	return (NULL);
}
