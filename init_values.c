/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:53:08 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/23 14:57:29 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_map		*init_map(void)
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	map->x = 0;
	map->y = 0;
	map->empty = 0;
	map->full = 0;
	map->path = 0;
	map->map = NULL;
	map->exit = 0;
	return (map);
}

t_cell		*init_cell(void)
{
	t_cell *cell;

	cell = (t_cell*)malloc(sizeof(t_cell));
	cell->parent_i = 0;
	cell->parent_j = 0;
	cell->f = 0;
	cell->g = 0;
	cell->h = 0;
	return (cell);
}

t_coord		*init_coord(void)
{
	t_coord *coord;

	coord = (t_coord*)malloc(sizeof(t_coord));
	coord->x_entry = 0;
	coord->y_entry = 0;
	coord->x_exit = 0;
	coord->y_exit = 0;
	return (coord);
}

t_point		*init_point(t_coord *coord)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = coord->x_entry;
	point->y = coord->y_entry;
	point->papa = NULL;
	return (point);
}
