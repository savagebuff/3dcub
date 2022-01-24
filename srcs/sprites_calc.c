/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:22:25 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 19:34:43 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_vec	transform(t_cub *cub, int i)
{
	double		inv_det;
	t_vec		spr;
	t_vec		ret;
	t_vec		dir;
	t_vec		pln;

	dir = cub->parse.ply.dir;
	pln = cub->parse.ply.pln;
	spr.x = cub->parse.sprites[i].pos.x - cub->parse.ply.pos.x;
	spr.y = cub->parse.sprites[i].pos.y - cub->parse.ply.pos.y;
	inv_det = 1.0 / (pln.x * dir.y - pln.y * dir.x);
	ret.x = inv_det * (dir.y * spr.x - dir.x * spr.y);
	ret.y = inv_det * (pln.x * spr.y - pln.y * spr.x);
	return (ret);
}

static t_point	tips(int dim, int ssx, int w, int h)
{
	t_point	ret;

	ret.y = dim / 2 + h / 2;
	ret.x = dim / 2 + ssx;
	if (w)
	{
		if (ret.x >= w)
			ret.x = w - 1;
		if (ret.y >= h)
			ret.y = h - 1;
	}
	else
	{
		if (ret.x < 0)
			ret.x = 0;
		if (ret.y < 0)
			ret.y = 0;
	}
	return (ret);
}

static void	sprite_sort(t_cub *cub)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < cub->parse.spr_num)
	{
		j = i + 1;
		while (j < cub->parse.spr_num)
		{
			if (cub->parse.sprites[i].trans.y < cub->parse.sprites[j].trans.y)
			{
				tmp = cub->parse.sprites[i];
				cub->parse.sprites[i] = cub->parse.sprites[j];
				cub->parse.sprites[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sprites(t_cub *cub)
{
	int			i;

	i = 0;
	while (i < cub->parse.spr_num)
	{
		cub->parse.sprites[i].trans = transform(cub, i);
		i++;
	}
	sprite_sort(cub);
	i = 0;
	while (i < cub->parse.spr_num)
	{
		cub->parse.sprites[i].scr_x = (int)((WIDTH / 2)
				* (1 + cub->parse.sprites[i].trans.x
					/ cub->parse.sprites[i].trans.y));
		cub->parse.sprites[i].dim = abs((int)(HEIGHT
					/ cub->parse.sprites[i].trans.y));
		cub->parse.sprites[i].d_s = tips(-cub->parse.sprites[i].dim,
				cub->parse.sprites[i].scr_x, 0, HEIGHT);
		cub->parse.sprites[i].d_e = tips(cub->parse.sprites[i].dim,
				cub->parse.sprites[i].scr_x, WIDTH,
				HEIGHT);
		sprite_render(cub, i);
		i++;
	}
}
