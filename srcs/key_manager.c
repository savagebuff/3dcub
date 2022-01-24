/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:30:37 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 19:40:56 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	if (keycode == 53)
		cub->keys.esc = 1;
	else if (keycode == 13)
		cub->keys.w_k = 1;
	else if (keycode == 0)
		cub->keys.a_k = 1;
	else if (keycode == 1)
		cub->keys.s_k = 1;
	else if (keycode == 2)
		cub->keys.d_k = 1;
	else if (keycode == 123)
		cub->keys.l_k = 1;
	else if (keycode == 124)
		cub->keys.r_k = 1;
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == 53)
		cub->keys.esc = 0;
	else if (keycode == 13)
		cub->keys.w_k = 0;
	else if (keycode == 0)
		cub->keys.a_k = 0;
	else if (keycode == 1)
		cub->keys.s_k = 0;
	else if (keycode == 2)
		cub->keys.d_k = 0;
	else if (keycode == 123)
		cub->keys.l_k = 0;
	else if (keycode == 124)
		cub->keys.r_k = 0;
	return (0);
}

int	key_close(t_cub *cub)
{
	if (cub->mlx_win)
		mlx_destroy_window(cub->mlx, cub->mlx_win);
	ft_clear_game(cub);
	exit(0);
	return (0);
}

int	mv_manager(t_cub *cub)
{
	if (cub->keys.esc)
		key_close(cub);
	if (cub->keys.a_k)
		move(cub, cub->parse.ply.pos, cub->parse.ply.pln, -MOV_SPD);
	if (cub->keys.d_k)
		move(cub, cub->parse.ply.pos, cub->parse.ply.pln, MOV_SPD);
	if (cub->keys.w_k)
		move(cub, cub->parse.ply.pos, cub->parse.ply.dir, MOV_SPD);
	if (cub->keys.s_k)
		move(cub, cub->parse.ply.pos, cub->parse.ply.dir, -MOV_SPD);
	if (cub->keys.l_k)
		rotate(cub, -ROT_SPD);
	if (cub->keys.r_k)
		rotate(cub, ROT_SPD);
	return (0);
}
