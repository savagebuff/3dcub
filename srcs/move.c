/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:41:58 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 19:43:18 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate(t_cub *cub, double rot_spd)
{
	t_vec	dir;
	t_vec	pln;

	dir = cub->parse.ply.dir;
	pln = cub->parse.ply.pln;
	cub->parse.ply.dir.x = dir.x * cos(rot_spd) - dir.y * sin(rot_spd);
	cub->parse.ply.dir.y = dir.x * sin(rot_spd) + dir.y * cos(rot_spd);
	cub->parse.ply.pln.x = pln.x * cos(rot_spd) - pln.y * sin(rot_spd);
	cub->parse.ply.pln.y = pln.x * sin(rot_spd) + pln.y * cos(rot_spd);
}

void	move(t_cub *cub, t_vec pos, t_vec vec, double mov_spd)
{
	if (ft_is_valid(cub->parse.map[(int)pos.y][(int)(pos.x + vec.x * mov_spd)])
		&& cub->parse.map[(int)pos.y][(int)(pos.x + vec.x * mov_spd)] != '2')
		cub->parse.ply.pos.x += vec.x * mov_spd;
	if (ft_is_valid(cub->parse.map[(int)(pos.y + vec.y * mov_spd)][(int)pos.x])
		&& cub->parse.map[(int)(pos.y + vec.y * mov_spd)][(int)pos.x] != '2')
		cub->parse.ply.pos.y += vec.y * mov_spd;
}
