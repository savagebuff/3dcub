/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:42:37 by choney            #+#    #+#             */
/*   Updated: 2021/04/25 13:43:06 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*arr;
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	arr = (char *)malloc(sizeof(*str) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
