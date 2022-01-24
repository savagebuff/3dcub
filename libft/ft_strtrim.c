/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:56:27 by choney            #+#    #+#             */
/*   Updated: 2021/04/25 17:07:30 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intstr(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	i = 0;
	if (s1 && s1[i] != '\0')
	{
		end = ft_strlen(s1) - 1;
		while (s1[start] && ft_intstr(s1[start], set))
			start++;
		while (end > start && ft_intstr(s1[end], set))
			end--;
		str = malloc(sizeof(char) * (end - start + 2));
		if (!str)
			return (NULL);
		while (start <= end)
			str[i++] = s1[start++];
	}
	else
		str = malloc(sizeof(*s1));
	str[i] = '\0';
	return (str);
}
