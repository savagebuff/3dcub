/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:20:45 by choney            #+#    #+#             */
/*   Updated: 2022/01/23 14:35:57 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_last_line(t_mapll *map)
{
	t_mapll	*tmp;
	int		i;

	if (!map)
		return (1);
	tmp = map;
	i = 0;
	while (tmp && tmp->next)
		tmp = tmp->next;
	while (tmp && tmp->line && tmp->line[i])
	{
		if (ft_is_valid(tmp->line[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_arrdel(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		ft_str_free(&(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

int	ft_array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

void	ft_str_free(char **s)
{
	if (s)
	{
		free((void *)*s);
		*s = NULL;
	}
}

int	ft_quit(char *msg, char *path, t_cub *cub)
{
	ft_putendl_fd("ERROR", 2);
	ft_putstr_fd(msg, 2);
	if (path)
		ft_putendl_fd(path, 2);
	else
		ft_putendl_fd("", 2);
	ft_clear_game(cub);
	exit(1);
	return (0);
}
