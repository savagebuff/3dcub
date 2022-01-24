/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:13:00 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 19:34:15 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	delta(t_cub *cub, int i)
{
	cub->cam.hit = 0;
	cub->cam.camera = 2 * i / (double)WIDTH - 1;
	cub->cam.ray.x = cub->parse.ply.dir.x + cub->parse.ply.pln.x
		* cub->cam.camera;
	cub->cam.ray.y = cub->parse.ply.dir.y + cub->parse.ply.pln.y
		* cub->cam.camera;
	cub->cam.map.x = (int)cub->parse.ply.pos.x;
	cub->cam.map.y = (int)cub->parse.ply.pos.y;
	cub->cam.deltadist.x = sqrt(1 + pow(cub->cam.ray.y, 2)
			/ pow(cub->cam.ray.x, 2));
	cub->cam.deltadist.y = sqrt(1 + pow(cub->cam.ray.x, 2)
			/ pow(cub->cam.ray.y, 2));
	if (cub->cam.ray.y == 0)
		cub->cam.deltadist.x = 0;
	else
		if (cub->cam.ray.x == 0)
			cub->cam.deltadist.x = 1;
	if (cub->cam.ray.x == 0)
		cub->cam.deltadist.y = 0;
	else
		if (cub->cam.ray.y == 0)
			cub->cam.deltadist.y = 1;
}

void	side_distance(t_cub *cub)
{
	if (cub->cam.ray.x < 0)
	{
		cub->cam.step.x = -1;
		cub->cam.sidedist.x = (cub->parse.ply.pos.x - cub->cam.map.x)
			* cub->cam.deltadist.x;
	}
	else
	{
		cub->cam.step.x = 1;
		cub->cam.sidedist.x = (cub->cam.map.x + 1.0 - cub->parse.ply.pos.x)
			* cub->cam.deltadist.x;
	}
	if (cub->cam.ray.y < 0)
	{
		cub->cam.step.y = -1;
		cub->cam.sidedist.y = (cub->parse.ply.pos.y - cub->cam.map.y)
			* cub->cam.deltadist.y;
	}
	else
	{
		cub->cam.step.y = 1;
		cub->cam.sidedist.y = (cub->cam.map.y + 1.0 - cub->parse.ply.pos.y)
			* cub->cam.deltadist.y;
	}
}

void	dda(t_cub *cub)
{
	while (cub->cam.hit == 0)
	{
		if (cub->cam.sidedist.x < cub->cam.sidedist.y)
		{
			cub->cam.sidedist.x += cub->cam.deltadist.x;
			cub->cam.map.x += cub->cam.step.x;
			cub->cam.side = 0;
		}
		else
		{
			cub->cam.sidedist.y += cub->cam.deltadist.y;
			cub->cam.map.y += cub->cam.step.y;
			cub->cam.side = 3;
		}
		if (cub->cam.side == 0 && cub->cam.ray.x > 0)
			cub->cam.side = 2;
		else if (cub->cam.side == 3 && cub->cam.ray.y < 0)
			cub->cam.side = 1;
		if (cub->parse.map[cub->cam.map.y][cub->cam.map.x] == '1')
			cub->cam.hit = 1;
	}
}

void	wall(t_cub *cub)
{
	if (cub->cam.side == 0 || cub->cam.side == 2)
		cub->cam.pwd = (cub->cam.map.x - cub->parse.ply.pos.x
				+ (1 - cub->cam.step.x) / 2) / cub->cam.ray.x;
	else
		cub->cam.pwd = (cub->cam.map.y - cub->parse.ply.pos.y
				+ (1 - cub->cam.step.y) / 2) / cub->cam.ray.y;
	cub->cam.lineheight = (int)(HEIGHT / cub->cam.pwd);
	cub->cam.drawstart = (-cub->cam.lineheight / 2) + (HEIGHT / 2);
	if (cub->cam.drawstart < 0)
		cub->cam.drawstart = 0;
	cub->cam.drawend = cub->cam.lineheight / 2 + (HEIGHT / 2);
	if (cub->cam.drawend >= HEIGHT)
		cub->cam.drawend = HEIGHT - 1;
	if (cub->cam.side == 0 || cub->cam.side == 2)
		cub->cam.wallx = cub->parse.ply.pos.y + cub->cam.pwd * cub->cam.ray.y;
	else
		cub->cam.wallx = cub->parse.ply.pos.x + cub->cam.pwd * cub->cam.ray.x;
	cub->cam.wallx -= floor(cub->cam.wallx);
	cub->cam.texture.x = (int)(cub->cam.wallx * (double)(TEX_WID));
	if (cub->cam.side == 1 || cub->cam.side == 2)
		cub->cam.texture.x = cub->cam.texture.x - 1;
	if (cub->cam.side == 3 || cub->cam.side == 0)
		cub->cam.texture.x = TEX_WID - cub->cam.texture.x - 1;
	cub->cam.texstep = 1.0 * TEX_HEI / cub->cam.lineheight;
}
