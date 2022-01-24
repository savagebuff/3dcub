/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:21:44 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 20:22:21 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	is_ws(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	else
		return (0);
}

static int	word_count(char const *s)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (s[i])
	{
		while (is_ws(s[i]) && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		while (!is_ws(s[i]) && s[i] != '\0')
			i++;
		ret++;
	}
	return (ret);
}

static char	*get_str(char const *s, int i, int j)
{
	int		k;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!ret)
		return (NULL);
	k = 0;
	while (i < j)
		ret[k++] = s[i++];
	ret[k] = '\0';
	return (ret);
}

static void	leakprotector(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split_whitespaces(char *s, int i, int j, int in)
{
	char	**ret;

	ret = (char **)ft_calloc((word_count(s) + 1), sizeof(char *));
	if (!s || !ret)
		return (NULL);
	in = 0;
	i = 0;
	while (s[i])
	{
		while (is_ws(s[i]) && s[i++] != '\0')
		j = i;
		while (s[i] && !is_ws(s[j]) && s[j] != '\0')
			j++;
		if (s[i])
		{
			ret[in] = get_str(s, i, j);
			if (!ret[in++])
			{
				leakprotector(ret, in);
				return (NULL);
			}
		}
		i = j;
	}
	return (ret);
}
