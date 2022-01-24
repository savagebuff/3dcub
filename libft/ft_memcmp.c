/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:15:40 by choney            #+#    #+#             */
/*   Updated: 2021/04/21 20:26:51 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*mass1;
	unsigned char	*mass2;
	size_t			i;

	i = 0;
	mass1 = (unsigned char *)arr1;
	mass2 = (unsigned char *)arr2;
	while (i < n)
	{
		if (mass1[i] != mass2[i])
			return (mass1[i] - mass2[i]);
		i++;
	}
	return (0);
}
