/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:06:12 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 16:48:16 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_identifier_fill(int id, char **array, t_cub *cub)
{
	if (id == F_ID)
		cub->parse.floor = ft_color_fill(array[1], cub);
	else if (id == C_ID)
		cub->parse.ceiling = ft_color_fill(array[1], cub);
	else if (id == NO_ID)
		cub->parse.paths.north = ft_path_fill(array[1], cub);
	else if (id == SO_ID)
		cub->parse.paths.south = ft_path_fill(array[1], cub);
	else if (id == EA_ID)
		cub->parse.paths.east = ft_path_fill(array[1], cub);
	else if (id == WE_ID)
		cub->parse.paths.west = ft_path_fill(array[1], cub);
}

static void	ft_id_seek_in_fill(char *line, t_cub *cub)
{
	char	**array;
	int		id;
	int		ln;

	array = ft_split_whitespaces(line, 0, 0, 0);
	ln = ft_array_len(array);
	id = ft_is_id(array[0], cub->parse.ids);
	if (id == 0)
	{
		if (array)
			ft_arrdel(&array);
		ft_quit("Identifier issue", NULL, cub);
	}
	if (id == MP_ID)
	{
		if (array)
			ft_arrdel(&array);
		ft_quit("Map must be last", NULL, cub);
	}
	ft_identifier_fill(id, array, cub);
	cub->parse.ids |= id;
	if (array)
		ft_arrdel(&array);
}

// |= - побитовое или

void	ft_id_fill(int fd, t_cub *cub)
{
	char	*line;
	int		n;

	line = NULL;
	while (cub->parse.ids < 63)
	{
		n = get_next_line(fd, &line, 0);
		if (n > 0 && line && line[0])
			ft_id_seek_in_fill(line, cub);
		if (!n && cub->parse.ids < 63)
		{
			if (line)
				ft_str_free(&line);
			ft_quit("Incomplete file", NULL, cub);
		}
		if (line)
			ft_str_free(&line);
	}
}

void	ft_parsing(char *path, t_cub *cub)
{
	int	fd;

	cub->parse = ft_struct_init();
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_quit("Failed to open file", NULL, cub);
	ft_id_fill(fd, cub);
	ft_map_fill(fd, cub);
	close(fd);
}
