/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:42:41 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 15:55:42 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_space(t_mapll *tmp, char *line, int i, t_cub *cub)
{
	if ((tmp && i < tmp->n && tmp->line[i] && tmp->line[i] != '1'
			&& tmp->line[i] != ' ') || (line[i + 1] != '1' && line[i + 1] != ' '
			&& line[i + 1] != '\0'))
		ft_quit("There's a hole in the map", NULL, cub);
}

int	ft_is_valid(char c)
{
	if (c == '0' || c == '2' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

t_vec	ft_fill_position(int a, int b)
{
	t_vec	vec;

	vec.x = a + 0.5;
	vec.y = b + 1.5;
	return (vec);
}

t_player	ft_fill_player(t_parse *parse, t_mapll *tmp, char *line, int i)
{
	t_player	pl;

	parse->ids |= PL_ID;
	pl.pos = ft_fill_position(i, tmp->i);
	if (line[i] == 'N')
	{
		pl.pln.x = 0.66;
		pl.dir.y = -1.0;
	}
	else if (line[i] == 'S')
	{
		pl.pln.x = -0.66;
		pl.dir.y = 1.0;
	}
	else if (line[i] == 'E')
	{
		pl.pln.y = 0.66;
		pl.dir.x = 1.0;
	}
	else if (line[i] == 'W')
	{
		pl.pln.y = -0.66;
		pl.dir.x = -1.0;
	}
	return (pl);
}

void	ft_twod_check(t_mapll *tmp, char *line, int i, t_cub *cub)
{
	if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		&& !(cub->parse.ids & PL_ID))
		cub->parse.ply = ft_fill_player(&(cub->parse), tmp, line, i);
	else if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E'
			|| line[i] == 'W') && (cub->parse.ids & PL_ID))
		ft_quit("It's a single player game verify map", NULL, cub);
	if (line[i] == '2')
		cub->parse.spr_num++;
	if ((tmp && tmp->line[i] != '1' && !ft_is_valid(tmp->line[i]))
		|| (line[i + 1] != '1' && !ft_is_valid(line[i + 1]))
		|| (ft_is_valid(line[i]) && !i))
		ft_quit("Invalid map", NULL, cub);
}
