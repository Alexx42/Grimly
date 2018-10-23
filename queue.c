/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <ale-goff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:52:51 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/23 11:27:51 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int	is_empty(t_queue *queue)
{
	if (queue->begin == NULL && queue->end == NULL)
		return (1);
	return (0);
}

void	push_queue(t_queue *queue, t_point *pt, int x, int y)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	new->papa = pt;
	if (is_empty(queue))
	{
		queue->begin = new;
		queue->end = new;
		return ;
	}
	queue->end->next = new;
	queue->end = new;
}

void	pop_queue(t_queue *queue)
{
	t_point *tmp;

	tmp = queue->begin;
	if (is_empty(queue))
		return ;
	if (queue->begin == queue->end)
	{
		queue->begin = NULL;
		queue->end = NULL;
	}
	else
		queue->begin = queue->begin->next;
}
