/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:44:47 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 19:40:28 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_trace(t_cub *cub)
{
	int	i;

	cub->image.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->image.data = mlx_get_data_addr(cub->image.img,
			&cub->image.bpp, &cub->image.size_line, &cub->image.endian);
	cub->cam.z_buff = (double *)malloc(sizeof(double) * WIDTH);
	i = -1;
	while (++i < WIDTH)
	{
		delta(cub, i);
		side_distance(cub);
		dda(cub);
		wall(cub);
		cub->cam.z_buff[i] = cub->cam.pwd;
		rendering(cub, i);
	}
	if (cub->parse.spr_num)
		sprites(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image.img, 0, 0);
	if (cub->cam.z_buff)
		free(cub->cam.z_buff);
}

static int	main_cast(t_cub *cub)
{
	mlx_destroy_image(cub->mlx, cub->image.img);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	mv_manager(cub);
	ft_trace(cub);
	return (0);
}

int	ft_ray_casting(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "cub3D");
	ft_texture_init(cub);
	ft_trace(cub);
	mlx_hook(cub->mlx_win, 2, 0, key_press, cub);
	mlx_hook(cub->mlx_win, 3, 0, key_release, cub);
	mlx_hook(cub->mlx_win, 17, 0, key_close, cub);
	mlx_loop_hook(cub->mlx, main_cast, cub);
	mlx_loop(cub->mlx);
	return (0);
}
