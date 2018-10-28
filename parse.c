/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:49:41 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/25 13:56:39 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

static void		parse_end(t_map *map, char **line)
{
	int i;

	i = (int)ft_strlen(*line);
	map->line = ft_strdup(*line);
	map->exit = (*line)[i - 1];
	map->entry = (*line)[i - 2];
	map->path = (*line)[i - 3];
	map->empty = (*line)[i - 4];
	map->full = (*line)[i - 5];
	(*line)[i - 5] = 0;
}

static int		parse_size(t_map *map, int fd)
{
	char	*line;
	int		i;
	int		res;

	i = 0;
	if (get_next_line(fd, &line) <= 0)
		return (1);
	parse_end(map, &line);
	while (line[i] && (res = 0) == 0)
	{
		while (ft_isdigit(line[i]) && line[i])
		{
			res += line[i] - 48;
			if (ft_isdigit(line[i + 1]))
				res = res * 10;
			i++;
		}
		if (map->x == 0)
			map->x = res;
		else if (map->y == 0)
			map->y = res;
		line[i] ? i++ : 0;
	}
	ft_strdel(&line);
	return (0);
}

static int		check_values(t_map *map, int count[2], int i, t_coord *coord)
{
	int j;

	j = 0;
	while (map->map[i][j])
	{
		if (((map->map[i][j] != map->entry) && (map->map[i][j] != map->exit) &&
		(map->map[i][j] != map->full) && (map->map[i][j] != map->empty)) ||
		(map->entry == map->exit))
			return (1);
		if (map->map[i][j] == map->entry)
		{
			coord->x_entry = i;
			coord->y_entry = j;
			count[0]++;
		}
		if (map->map[i][j] == map->exit)
		{
			coord->x_exit = i;
			coord->y_exit = j;
			count[1]++;
		}
		j++;
	}
	return (0);
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
		if (check_values(map, count, i, coord))
			return (1);
		ft_strdel(&line);
	}
	if (count[0] != 1 || count[1] <= 0)
		return (1);
	return (0);
}

int				parse_line(t_map *map, int fd, t_coord *coord, t_point **point)
{
	if (parse_size(map, fd) || parse_map(map, fd, coord))
		return (1);
	*point = init_point(coord);
	return (0);
}
