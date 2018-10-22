/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:45:25 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/22 12:51:28 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H

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
}					t_map

#endif
