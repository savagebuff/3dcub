/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:28:13 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 19:28:22 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_error(void)
{
	printf("Error\nUse: ./cub3D *.cub\n");
	return (1);
}

static t_keys	ft_keys_init(void)
{
	t_keys	keys;

	keys.w_k = 0;
	keys.a_k = 0;
	keys.s_k = 0;
	keys.d_k = 0;
	keys.l_k = 0;
	keys.r_k = 0;
	keys.esc = 0;
	return (keys);
}

static t_cub	ft_cub_init(void)
{
	t_cub	cub;

	cub.mlx = NULL;
	cub.mlx_win = NULL;
	cub.keys = ft_keys_init();
	return (cub);
}

int	ft_extension(char *path, char *text)
{
	int	n;
	int	m;

	n = ft_strlen(path);
	m = ft_strlen(text);
	if (ft_strcmp(path + n - m, text))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	cub = ft_cub_init();
	if (argc < 2 || argc > 3)
		return (ft_error());
	else if (ft_extension(argv[1], ".cub"))
		return (ft_error());
	ft_parsing(argv[1], &cub);
	ft_ray_casting(&cub);
	return (0);
}
