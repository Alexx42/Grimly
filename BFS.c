/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:24:22 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/23 16:48:00 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int			is_valid(int x, int y, t_map *map)
{
	return ((x >= 0) && (x < map->x) && (y >= 0) && (y < map->y));
}

int			visit_neighboor(t_queue *queue, int ***visited, t_map *map, t_point *cur)
{
	if (is_valid(cur->x + 1, cur->y, map) && visited[cur->x + 1][cur->y] == 0)
		push_queue(queue, cur, cur->x + 1, cur->y);
	if (is_valid(cur->x + 1, cur->y, map) && visited[cur->x + 1][cur->y] == 0)
		push_queue(queue, cur, cur->x + 1, cur->y);
	if (is_valid(cur->x + 1, cur->y, map) && visited[cur->x + 1][cur->y] == 0)
		push_queue(queue, cur, cur->x + 1, cur->y);
	if (is_valid(cur->x + 1, cur->y, map) && visited[cur->x + 1][cur->y] == 0)
		push_queue(queue, cur, cur->x + 1, cur->y);
	return (1);
}

static int	**create_visited(t_map *map)
{
	int		**visited;
	int		i;
	int		j;

	visited = (int **)malloc(sizeof(int *) * map->x + 1);
	i = -1;
	while (++i < map->x && (j = -1) == -1)
	{
		visited[i] = (int *)malloc(sizeof(int) * map->y + 1);
		while (++j < map->y)
		{
			if (map->map[i][j] == map->empty)
				visited[i][j] = 0;
			else if (map->map[i][j] == map->entry)
				visited[i][j] = 4;
			else if (map->map[i][j] == map->exit)
				visited[i][j] = 5;
			else if (map->map[i][j] == map->full)
				visited[i][j] = 1;
		}
	}
	return (visited);
}

int			bfs(t_map *map, t_point *src)
{
	int		**visited;
	t_queue	queue;
	t_point *curr;
	int		ret;
	// int		x;
	// int		y;
	visited = create_visited(map);
	for (int i = 0; i < map->x; i++)
	{
		for (int j = 0 ; j < map->y; j++)
		{
			ft_printf("%d", visited[i][j]);
		}
		ft_printf("\n");
	}
	queue.begin = src;
	queue.end = src;
	while (!is_empty(&queue))
	{
		curr = pop_queue(&queue);
		ret = visit_neighboor(&queue, &visited, map, curr);
		if (ret == 2)
			return (1);
	}
	return (0);
}
