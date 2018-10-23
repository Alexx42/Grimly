/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:24:22 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/23 13:49:03 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int			is_valid(int x, int y, t_map *map)
{
	return ((x >= 0) && (x < map->x) && (y >= 0) && (y < map->y));
}

int			bfs(t_map *map, t_point *src)
{
	int		visited[map->x][map->y];
	t_queue	queue;
	int		x;
	int		y;

	ft_memset(visited, 0, sizeof(visited));
	visited[src->x][src->y] = 0;
	queue.begin = src;
	queue.end = src;
	while (!is_empty(&queue))
	{

	}
	return (INT_MAX);
}
