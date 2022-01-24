/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:08:40 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 16:45:53 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_mapll	*new_node(char *line, t_mapll *prv)
{
	t_mapll	*map;

	map = (t_mapll *)malloc(sizeof(t_mapll));
	map->next = NULL;
	if (prv)
		map->i = prv->i + 1;
	else
		map->i = 0;
	map->line = ft_strdup(line);
	map->n = ft_strlen(line);
	return (map);
}

char	**ft_map_convert(t_mapll *map)
{
	t_mapll	*tmp;
	char	**ret;
	int		i;

	if (map)
	{
		i = ft_listlen(map) + 1;
		ret = (char **)malloc(sizeof(char *) * i);
		ret[i - 1] = NULL;
		i = 0;
		while (map)
		{
			tmp = map->next;
			ret[i] = ft_strdup(map->line);
			free(map->line);
			free(map);
			map = tmp;
			i++;
		}
		return (ret);
	}
	else
		return (NULL);
}

int	ft_check_end(t_mapll *tmp, int n)
{
	int	i;

	if (tmp && n > 0)
	{
		i = tmp->n - n;
		while (tmp->line[i])
		{
			if (ft_is_valid(tmp->line[i]))
				return (1);
			i++;
		}
	}
	return (0);
}

void	ft_check_store(char *line, t_cub *cub, t_mapll **map)
{
	t_mapll	*tmp;
	int		i;

	tmp = *map;
	while (tmp && tmp->next)
		tmp = tmp->next;
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			ft_check_space(tmp, line, i, cub);
		else if (ft_is_valid(line[i]) && tmp)
			ft_twod_check(tmp, line, i, cub);
		else if (ft_is_valid(line[i]) && !tmp)
			ft_quit("There's a hole in the map", NULL, cub);
		else if (line[i] != '1')
			ft_quit("Invalid map", NULL, cub);
		i++;
	}
	if (tmp && ft_check_end(tmp, tmp->n - ft_strlen(line)))
		ft_quit("Hole detected in the map.", NULL, cub);
	if (tmp)
		tmp->next = new_node(line, tmp);
	else
		*map = new_node(line, tmp);
}

void	ft_map_fill(int fd, t_cub *cub)
{
	t_mapll		*map;
	char		*line;
	int			n;

	line = NULL;
	map = NULL;
	n = get_next_line(fd, &line, 0);
	while (n >= 0)
	{
		if (!n && (!line || (line && !line[0])))
			break ;
		if (line && line[0])
			ft_check_store(line, cub, &map);
		else if ((!line || !line[0]) && map)
		{
			if (line)
				free(line);
			ft_quit("The map shouldn't contain empty lines", NULL, cub);
		}
		if (line)
			free(line);
		n = get_next_line(fd, &line, 0);
	}
	ft_map_fill2(line, cub, map);
}
