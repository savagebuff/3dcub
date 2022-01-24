/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:03:25 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 20:26:23 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_assign(t_cub *cub, int n, char *path)
{
	cub->text[n].img = mlx_xpm_file_to_image(cub->mlx, path,
			&(cub->text[n].width), &cub->text[n].height);
	if (!cub->text[n].img)
		ft_quit("Impossible to load a texture;\n", NULL, cub);
	cub->text[n].data = mlx_get_data_addr(cub->text[n].img,
			&(cub->text[n].bpp), &(cub->text[n].size_line),
			&(cub->text[n].endian));
}

void	ft_texture_init(t_cub *cub)
{
	ft_check_assign(cub, 0, cub->parse.paths.west);
	ft_check_assign(cub, 1, cub->parse.paths.north);
	ft_check_assign(cub, 2, cub->parse.paths.east);
	ft_check_assign(cub, 3, cub->parse.paths.south);
	ft_check_assign(cub, 4, "texture/sprite3.xpm");
}
