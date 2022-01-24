/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:25:23 by choney            #+#    #+#             */
/*   Updated: 2022/01/20 16:37:30 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_free_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->parse.map[i])
	{
		free(cub->parse.map[i]);
		i++;
	}
	free(cub->parse.map);
}

void	ft_clear_game(t_cub *cub)
{
	int	i;

	if (cub->parse.paths.north)
		free(cub->parse.paths.north);
	if (cub->parse.paths.south)
		free(cub->parse.paths.south);
	if (cub->parse.paths.east)
		free(cub->parse.paths.east);
	if (cub->parse.paths.west)
		free(cub->parse.paths.west);
	if (cub->parse.paths.sprite)
		free(cub->parse.paths.sprite);
	if (cub->parse.map)
		ft_free_map(cub);
	if (cub->parse.sprites)
		free(cub->parse.sprites);
	if (cub->mlx)
	{
		i = -1;
		while (++i < 5)
		{
			if (cub->text[i].img)
				mlx_destroy_image(cub->mlx, cub->text[i].img);
		}
	}
}
