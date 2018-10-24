/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BFS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:24:22 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/23 22:03:17 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int			is_valid(int x, int y, t_map *map, int **visited)
{
	return ((x >= 0) && (x < map->x) && (y >= 0) && (y < map->y)
	&& (visited[x][y] != 1) && (visited[x][y] != 4) && (visited[x][y] != 9));
}

int			visit_neighboor(t_queue *queue, int ***visited, t_map *map, t_point *cur)
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

void	print_path(t_point *curr, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (curr != NULL)
	{
		map->map[curr->x][curr->y] = map->path;
		curr = curr->papa;
	}
	while (i < map->x && (j = 0) == 0)
	{
		while (j < map->y)
		{
			ft_printf("%c", map->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
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
	int			**visited;
	t_queue		queue;
	t_point		*curr;
	int			ret;

	visited = create_visited(map);
	queue.begin = src;
	queue.end = src;
	while (!is_empty(&queue))
	{
		// ft_printf("x: %d\n", src->x);
		// ft_printf("y: %d\n", src->y);
		// ft_printf("SALUT\n");

		curr = pop_queue(&queue);
		ret = visit_neighboor(&queue, &visited, map, curr);
		// for (int i = 0; i < map->x; i++)
		// {
		// 	for (int j = 0 ; j < map->y; j++)
		// 	{
		// 		ft_printf("%d", visited[i][j]);
		// 	}
		// 	ft_printf("\n");
		// }
		if (ret == 2)
		{
			print_path(curr, map);
			return (1);
		}
	}
	return (0);
}
