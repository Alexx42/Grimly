/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:45:25 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/22 19:21:55 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>

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

t_map				*init_struct(void);
int					parse_line(t_map *map, int fd);

#endif
