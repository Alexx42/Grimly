/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:45:18 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/23 22:03:57 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	print_infos(t_map *map, t_coord *coord)
{
	ft_printf("x: %d\n", map->x);
	ft_printf("y: %d\n", map->y);
	ft_printf("empty: %c\n", map->empty);
	ft_printf("entry: %c\n", map->entry);
	ft_printf("full: %c\n", map->full);
	ft_printf("path: %c\n", map->path);
	ft_printf("exit: %c\n", map->exit);
	ft_printf("x_entry: : %c\n",coord->x_entry);
	ft_printf("y_entry: %c\n", coord->y_entry);
	ft_printf("x_exit: : %c\n",coord->x_exit);
	ft_printf("y_exit: : %c\n",coord->y_exit);
}

void	free_map(t_map *map, char **arr)
{
	int i;

	i = 0;
	while (i < map->x)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
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

int		main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	t_coord	*coord;
	t_point *point;
	int		i;

	i = 0;
	if (ac >= 2)
	{
		while  (av[++i])
		{
			fd = open(av[i], O_RDONLY);
			map = init_map();
			coord = init_coord();
			if (parse_line(map, fd, coord))
			{
				i < ac - 1 ? ft_printf("MAP ERROR\n\n") : ft_printf("MAP ERROR\n");
				continue ;
			}
			print_infos(map, coord);
			point = init_point(coord);
			if (bfs(map, point) == 0)
			{
				ft_printf("MAP ERROR\n");
				continue ;
			}
			free_map(map, map->map);
			close(fd);
			i < ac - 1 ? ft_printf("\n"): 0;
		}
	}
	return (0);
}
