/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:50:18 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/22 23:24:16 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int		is_valid(int x, int y, t_map *map)
{
	return ((x >= 0) && (x < map->x) && (y >= 0) && (y < map->y));
}

int		is_free_space(t_map *map, int x, int y)
{
	if (map->map[x][y] == map->empty)
		return (1);
	return (0);
}

int		is_finished(int x, int y, t_map *map)
{
	if (map->map[x][y] == map->exit)
		return (1);
	return (0);
}

void	star_search(t_map *map, t_coord *cord, t_cell *cell)
{
	if (is_valid(coord->x_entry, y_entry) == 0)
	{
		ft_printf("MAP ERROR\n")
		return ;
	}
	if (is_valid(coord->x_exit, y_exit) == 0)
	{
		ft_printf("MAP ERROR\n")
		return ;
	}

	if (is_free_space(map, x_entry, y_entry) == 0 ||
	is_free_space(map, x_entry, y_entry))
	{
		ft_printf("MAP ERROR\n");
		return ;
	}

	if (is_finished(x_entry, y_entry, map))
	{
		ft_printf("ARRIVED!\n");
		return ;
	}
}
