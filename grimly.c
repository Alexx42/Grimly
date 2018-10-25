/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:45:18 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/24 20:19:04 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"



int 	grimly(int fd)
{
	t_map	*map;
	t_coord	*coord;
	t_point *point;

	map = init_map();
	coord = init_coord();
	if (parse_line(map, fd, coord, &point) || bfs(map, point))
		return (1);
	ft_freemap(map->map, map->x);
	return (0);

}

int		main(int ac, char **av)
{
	int		fd;
	int		i;

	i = 1;
	if (ac == 1)
	{
		if (grimly(0))
			ft_printf("MAP ERROR\n");
	}
	else
		while (i < ac)
		{
			if ((fd = open(av[i], O_RDONLY)) == -1)
				ft_printf("MAP ERROR\n");
			else if (grimly(fd))
				ft_printf("MAP ERROR\n");
			i++;
		}
	return (0);
}

