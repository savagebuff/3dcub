/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:23:20 by choney            #+#    #+#             */
/*   Updated: 2022/01/20 20:12:41 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*s_stock(char *a, char *b)
{
	char	*p;

	p = a;
	a = ft_strjoin(p, b);
	free(p);
	return (a);
}

static char	*s_free(char *s, int i)
{
	char	*temp;

	temp = s;
	if (temp + i)
		s = ft_strdup(temp + i);
	else
		s = NULL;
	free(temp);
	return (s);
}

static int	cut(char **chr, char **arr, char **line)
{
	if (!(*chr))
		*chr = ft_strchr(*arr, '\n');
	if (**arr == '\0')
	{
		free(*arr);
		*line = NULL;
		*line = ft_strdup("");
		return (!(*line));
	}
	if (*chr)
	{
		*line = ft_strndup(*arr, *chr - *arr);
		*arr = s_free(*arr, *chr - *arr + 1);
	}
	else
	{
		*line = ft_strdup(*arr);
		free(*arr);
		*arr = NULL;
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line, int ret)
{
	char		*buf;
	char		*chr;
	static char	*arr = NULL;

	chr = NULL;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!arr)
	{
		arr = (char *)malloc(sizeof(char));
		*arr = '\0';
	}
	if (line == NULL || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0 || !buf)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret)
	{
		buf[ret] = '\0';
		arr = s_stock(arr, buf);
		chr = ft_strchr(arr, '\n');
		if (chr)
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (cut(&chr, &arr, line));
}
