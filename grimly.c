/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:45:18 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/22 18:07:39 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void	print_infos(t_map *map)
{
	ft_printf("x: %d\n", map->x);
	ft_printf("y: %d\n", map->y);
	ft_printf("empty: %c\n", map->empty);
	ft_printf("entry: %c\n", map->entry);

	ft_printf("full: %c\n", map->full);
	ft_printf("path: %c\n", map->path);
	ft_printf("exit: %c\n", map->exit);
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
	int		i;

	i = 1;
	if (ac >= 2)
	{
		while (av[i])
		{
			fd = open(av[i], O_RDONLY);
			map = init_struct();
			if (parse_line(map, fd))
			{
				ft_printf("MAP ERROR\n");
				return (0);
			}
			print_infos(map);
			print_map(map);
			close(fd);
			i++;
		}
	}
	return (0);
}
