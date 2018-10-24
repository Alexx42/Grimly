/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:45:25 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/23 16:45:49 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>

int					ft_printf(const char *fmt, ...);
typedef struct		s_map
{
	int				x;
	int				y;
	char			full;
	char			path;
	char			entry;
	char			exit;
	char			empty;
	char			**map;
}					t_map;

typedef struct		s_cell
{
	int				parent_i;
	int				parent_j;
	double			f;
	double			g;
	double			h;
}					t_cell;

typedef struct		s_point
{
	int				x;
	int				y;
	struct s_point	*papa;
	struct s_point	*next;
}					t_point;

typedef struct		s_queue
{
	t_point			*begin;
	t_point			*end;
}					t_queue;

typedef struct		s_coord
{
	int				x_entry;
	int				y_entry;
	int				x_exit;
	int				y_exit;
}					t_coord;

t_map				*init_map(void);
t_coord				*init_coord(void);
t_cell				*init_cell(void);
int					is_empty(t_queue *queue);
void				push_queue(t_queue *queue, t_point *pt, int x, int y);
t_point				*pop_queue(t_queue *queue);
int					parse_line(t_map *map, int fd, t_coord *coord);
t_point				*init_point(t_coord *cord);
int					bfs(t_map *map, t_point *src);

#endif
