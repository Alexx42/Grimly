/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:53:08 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/22 13:39:53 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_map	*init_struct()
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
