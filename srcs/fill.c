/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:50:17 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 18:41:05 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_path_fill(char *str, t_cub *cub)
{
	int	fd;

	if (ft_extension(str, ".xpm"))
		ft_quit("Invalid extension: ", str, cub);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_quit("Error\ncouldn't open file: ", str, cub);
	close (fd);
	return (ft_strdup(str));
}

static void	ft_check_digit(char **arr, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		while (arr[i][j])
		{
			if ((ft_isdigit(arr[i][j])) == 0)
			{
				if (arr)
					ft_arrdel(&arr);
				ft_quit("Colors needs can be in rgb format", NULL, cub);
			}
			j++;
		}
		i++;
	}
}

t_rgb	ft_color_fill(char *str, t_cub *cub)
{
	char	**arr;
	t_rgb	ret;

	arr = ft_split(str, ',');
	if (ft_array_len(arr) != 3)
	{
		if (arr)
			ft_arrdel(&arr);
		ft_quit("Colors needs can be in rgb format", NULL, cub);
	}
	ft_check_digit(arr, cub);
	ret.r = ft_atoi(arr[0]);
	ret.g = ft_atoi(arr[1]);
	ret.b = ft_atoi(arr[2]);
	if (ret.r > 255 || ret.r < 0 || ret.g > 255 || ret.g < 0 || ret.b > 255
		|| ret.b < 0)
	{
		if (arr)
			ft_arrdel(&arr);
		ft_quit("Incorrect color value", NULL, cub);
	}
	if (arr)
		ft_arrdel(&arr);
	return (ret);
}

t_sprite	*ft_sprite_fill(t_parse *parse)
{
	t_sprite	*ret;
	int			i;
	int			j;
	int			k;

	if (parse->spr_num)
		ret = (t_sprite *)malloc(parse->spr_num * sizeof(t_sprite));
	else
		return (NULL);
	i = -1;
	k = 0;
	while (parse->map[++i])
	{
		j = -1;
		while (parse->map[i][++j])
		{
			if (parse->map[i][j] == '2')
			{
				ret[k].pos.x = j + 0.5;
				ret[k].pos.y = i + 0.5;
				k++;
			}
		}
	}
	return (ret);
}

void	ft_map_fill2(char *line, t_cub *cub, t_mapll *map)
{
	if (line)
		free(line);
	if (!map)
		ft_quit("No map found", NULL, cub);
	else
		(cub->parse.ids |= MP_ID);
	if (ft_check_last_line(map))
		ft_quit("Invalid last line", NULL, cub);
	cub->parse.map = ft_map_convert(map);
	cub->parse.sprites = ft_sprite_fill(&(cub->parse));
	if (!(cub->parse.ids & PL_ID))
		ft_quit("Player no find", NULL, cub);
}
