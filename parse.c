/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:49:41 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/22 23:08:06 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

static void		parse_end(t_map *map, char *line)
{
	int i;

	i = ft_strlen(line);
	map->exit = line[i - 1];
	map->entry = line[i - 2];
	map->path = line[i - 3];
	map->empty = line[i - 4];
	map->full = line[i - 5];
}

static int		parse_size(t_map *map, int fd)
{
	char	*line;
	int		i;
	int		res;

	res = 0;
	i = -1;
	if (get_next_line(fd, &line) <= 0)
		return (1);
	while (line[++i])
	{
		res = 0;
		while (ft_isdigit(line[i]) && line[i] != '\0')
		{
			res += line[i] - 48;
			if (ft_isdigit(line[i + 1]))
				res = res * 10;
			i++;
		}
		map->x == 0 ? map->x = res : 0;
		map->y == 0 ? map->y = res : 0;
	}
	parse_end(map, line);
	ft_strdel(&line);
	return (0);
}

static void		check_values(t_map *map, int count[2], int i, t_coord *coord)
{
	int j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == map->entry)
		{
			coord->x_entry = i + 48;
			coord->y_entry = j + 48;
			count[0]++;
		}
		if (map->map[i][j] == map->exit)
		{
			coord->x_exit = i + 48;
			coord->y_exit = j + 48;
			count[1]++;
		}
		j++;
	}
}

static int		parse_map(t_map *map, int fd, t_coord *coord)
{
	char	*line;
	int		i;
	int		count[2];

	i = -1;
	count[0] = 0;
	count[1] = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->x + 1));
	while (++i < map->x)
	{
		if (get_next_line(fd, &line) <= 0 || ft_strlen(line) != (size_t)map->y)
			return (1);
		map->map[i] = ft_strdup(&line[0]);
		check_values(map, count, i, coord);
		ft_strdel(&line);
	}
	if (count[0] != 1 || count[1] <= 0)
		return (1);
	return (0);
}

int				parse_line(t_map *map, int fd, t_coord *coord)
{
	if (parse_size(map, fd) == 1 || parse_map(map, fd, coord) == 1)
		return (1);
	return (0);
}
