/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:49:41 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/22 18:20:36 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

void		parse_end(t_map *map, char *line)
{
	int i;

	i = ft_strlen(line);
	map->exit = line[i - 1];
	map->entry = line[i - 2];
	map->path = line[i - 3];
	map->empty = line[i - 4];
	map->full = line[i - 5];
}

int		parse_size(t_map *map, int fd)
{
	char	*line;
	int		i;
	int		res;

	res = 0;
	i = 0;
	if (get_next_line(fd, &line) <= 0)
		return (1);
	while (line[i])
	{
		res = 0;
		while (ft_isdigit(line[i]) && line[i] != '\0')
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
		i++;
	}
	parse_end(map, line);
	return (0);
}

int			parse_map(t_map *map, int fd)
{
	char	*line;
	int		i;
	int		count[2];
	int		j;

	i = 0;
	count[0] = 0;
	count[1] = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->x + 1));
	while (i < map->x && (j = 0) == 0)
	{
		if (get_next_line(fd, &line) <= 0 || ft_strlen(line) != (size_t)map->y)
			return (1);
		map->map[i] = ft_strdup(&line[0]);
		while (map->map[i][j++])
		{
			if (map->map[i][j] == map->entry)
				count[0]++;
			if (map->map[i][j] == map->exit)
				count[1]++;

		}
		ft_strdel(&line);
		i++;
	}
	if (count[0] != 1 || count[1] <= 0)
		return (1);
	return (0);
}

int			parse_line(t_map *map, int fd)
{
	if (parse_size(map, fd) == 1 || parse_map(map, fd) == 1)
		return (1);
	return (0);
}
