/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:24:22 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/24 19:46:25 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

static int			is_valid(int x, int y, t_map *map, int **visited)
{
	return ((x >= 0) && (x < map->x) && (y >= 0) && (y < map->y)
	&& (visited[x][y] != 1) && (visited[x][y] != 4) && (visited[x][y] != 9));
}

static int			visit_neighboor(t_queue *queue,
					int ***visited, t_map *map, t_point *cur)
{
	if (map->map[cur->x][cur->y] == map->exit)
		return (2);
	if (is_valid(cur->x - 1, cur->y, map, *visited))
	{
		(*visited)[cur->x - 1][cur->y] = 9;
		push_queue(queue, cur, cur->x - 1, cur->y);
	}
	if (is_valid(cur->x, cur->y - 1, map, *visited))
	{
		(*visited)[cur->x][cur->y - 1] = 9;
		push_queue(queue, cur, cur->x, cur->y - 1);
	}
	if (is_valid(cur->x, cur->y + 1, map, *visited))
	{
		(*visited)[cur->x][cur->y + 1] = 9;
		push_queue(queue, cur, cur->x, cur->y + 1);
	}
	if (is_valid(cur->x + 1, cur->y, map, *visited))
	{
		(*visited)[cur->x + 1][cur->y] = 9;
		push_queue(queue, cur, cur->x + 1, cur->y);
	}
	return (0);
}

static int			print_path(t_point *curr, t_map *map)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (curr != NULL)
	{
		if (map->map[curr->x][curr->y] != map->entry &&
			map->map[curr->x][curr->y] != map->exit)
			map->map[curr->x][curr->y] = map->path;
		curr = curr->papa;
		count++;
	}
	while (++i < map->x)
		ft_putendl(map->map[i]);
	return (count);
}

static int			**create_visited(t_map *map)
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
			if (map->map[i][j] == map->entry)
				visited[i][j] = 4;
			else if (map->map[i][j] == map->exit)
				visited[i][j] = 5;
			else if (map->map[i][j] == map->full)
				visited[i][j] = 1;
			else
				visited[i][j] = 0;
		}
	}
	return (visited);
}

int					bfs(t_map *map, t_point *src)
{
	int			**visited;
	t_queue		queue;
	t_point		*curr;
	int			ret;
	int			count;

	visited = create_visited(map);
	queue.begin = src;
	queue.end = src;
	while (!is_empty(&queue))
	{
		curr = pop_queue(&queue);
		ret = visit_neighboor(&queue, &visited, map, curr);
		if (ret == 2)
		{
			count = print_path(curr, map);
			ft_printf("RESULT IN %d STEPS\n", count - 2);
			return (0);
		}
	}
	return (1);
}
