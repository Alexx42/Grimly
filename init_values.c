/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:53:08 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/22 12:55:26 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

t_map	*init_values()
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	map->x = 0;
	map->y = 0;
	map->empy = 0;
	map->full = 0;
	map->path = 0;
	map->map = NULL;
	map->exit = 0;
}
