/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:47:47 by choney            #+#    #+#             */
/*   Updated: 2021/05/22 16:18:15 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_len(long long *tmp)
{
	unsigned int	len;
	long long		n;

	n = *tmp;
	len = 0;
	if (n < 0)
	{
		n = n * -1;
		*tmp = *tmp * (-1);
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_malloc_str(long long n, unsigned int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long long		i;
	unsigned int	len;
	char			*res;

	i = n;
	len = ft_len(&i);
	res = ft_malloc_str(n, len);
	if (!res)
		return (NULL);
	while (i > 0)
	{
		res[--len] = (i % 10) + '0';
		i = i / 10;
	}
	return (res);
}
