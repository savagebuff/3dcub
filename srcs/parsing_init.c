/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:38:56 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 20:20:13 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_path	ft_init_path(void)
{
	t_path	path;

	path.north = NULL;
	path.south = NULL;
	path.east = NULL;
	path.west = NULL;
	path.sprite = NULL;
	return (path);
}

t_rgb	ft_init_color(void)
{
	t_rgb	rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.g = 0;
	return (rgb);
}

t_player	ft_init_player(void)
{
	t_player	ply;

	ply.pos.x = 0;
	ply.pos.y = 0;
	ply.dir.x = 0;
	ply.dir.y = 0;
	ply.pln.x = 0;
	ply.pln.y = 0;
	return (ply);
}

t_parse	ft_struct_init(void)
{
	t_parse	st;

	st.ids = 0;
	st.spr_num = 0;
	st.paths = ft_init_path();
	st.floor = ft_init_color();
	st.ceiling = ft_init_color();
	st.ply = ft_init_player();
	st.sprites = NULL;
	st.map = NULL;
	return (st);
}
