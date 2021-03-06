/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-goff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:07:38 by ale-goff          #+#    #+#             */
/*   Updated: 2018/10/04 22:07:39 by ale-goff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append3(t_list **head_ref, char *new_data, int content_size)
{
	t_list *new;
	t_list *last;

	last = *head_ref;
	new = (t_list*)(malloc(sizeof(t_list)));
	new->content = ft_strdup(new_data);
	new->next = NULL;
	new->content_size = (size_t)content_size;
	if (*head_ref == NULL)
	{
		*head_ref = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

int		list_size2(t_list *lst)
{
	int		count;
	t_list	*cur;

	cur = lst;
	count = 0;
	while (cur != NULL)
	{
		count += ft_strlen(cur->content);
		cur = cur->next;
	}
	return (count);
}

void	print_list2(t_list *lst)
{
	while (lst != NULL)
	{
		write(1, lst->content, (size_t)lst->content_size);
		lst = lst->next;
	}
}

void	delete_list2(t_list **head_ref)
{
	t_list	*current;
	t_list	*next;

	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*head_ref = NULL;
}

void	push(t_list **head_ref, char *new_data, int content_size)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	new_node->content = new_data;
	new_node->content_size = (size_t)content_size;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
