/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:31:13 by choney            #+#    #+#             */
/*   Updated: 2022/01/22 17:50:38 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			return (1);
		if (line[i] == 'W' && line[i + 1] == 'E')
			return (1);
		if (line[i] == 'S' && !line[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_id(char *c, int ids)
{
	int	ret;

	ret = 0;
	if (!ft_strcmp(c, "C") && !(ids & C_ID))
		ret = C_ID;
	if (!ft_strcmp(c, "F") && !(ids & F_ID))
		ret = F_ID;
	if (!ft_strcmp(c, "NO") && !(ids & NO_ID))
		ret = NO_ID;
	if (!ft_strcmp(c, "SO") && !(ids & SO_ID))
		ret = SO_ID;
	if (!ft_strcmp(c, "WE") && !(ids & WE_ID))
		ret = WE_ID;
	if (!ft_strcmp(c, "EA") && !(ids & EA_ID))
		ret = EA_ID;
	if (!ft_map_line(c))
		ret = MP_ID;
	return (ret);
}
