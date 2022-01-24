/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:16:54 by choney            #+#    #+#             */
/*   Updated: 2021/04/19 18:27:30 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i - 1 >= 0)
	{
		if (str[i] == (char)c)
			return ((char *) str + i);
		i--;
	}
	if (str[i] == (char)c)
		return ((char *) str + i);
	return (NULL);
}
