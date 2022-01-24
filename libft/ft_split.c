/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:51:25 by choney            #+#    #+#             */
/*   Updated: 2021/04/26 21:42:58 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	ft_count(char **s, char c)
{
	unsigned int	count;

	count = 0;
	while (**s != '\0' && **s != c)
	{
		count++;
		(*s)++;
	}
	return (count);
}

static unsigned int	ft_word_nb(char *s, char c)
{
	unsigned int	i;
	unsigned int	nbr;

	if (!s)
		return (0);
	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			nbr++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (nbr);
}

static char	**ft_malloc_error(char **str)
{
	unsigned char	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nbr;
	char			**str;
	char			*s1;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	nbr = ft_word_nb(s1, c);
	str = (char **)malloc(sizeof(char *) * (nbr + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 != '\0' && i < nbr)
	{
		while (*s1 == c)
			s1++;
		str[i] = ft_substr(s1, 0, ft_count(&s1, c));
		if (!str[i])
			return (ft_malloc_error(str));
		i++;
	}
	str[i] = NULL;
	return (str);
}
