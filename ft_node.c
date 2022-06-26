/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:06:09 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/21 10:52:18 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

void	initialize_list(t_linked_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

void	add_head(t_linked_list *list, void *data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->data = data;
	if (list->head == NULL)
	{
		list->tail = node;
		node->next = NULL;
	}
	else
		node->next = list->head;
	list->head = node;
}

void	add_tail(t_linked_list *list, void *data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->data = data;
	node->next = NULL;
	if (list->head == NULL)
		list->head = node;
	else
		list->head->next = node;
	list->tail = node;
}

void	delete_node(t_linked_list *list, t_node *node)
{
	t_node	*tmp;

	if (node == list->head)
	{
		if (list->head->next == NULL)
		{
			list->tail = NULL;
			list->head = list->tail;
		}
		else
			list->head = list->head->next;
	}
	else
	{
		tmp = list->head;
		while (tmp != NULL && tmp->next != node)
			tmp = tmp->next;
		if (list->tail == node)
			list->tail = tmp;
	}
	free(node);
}

t_node	*get_node(t_linked_list *list, int (*compare)(void *d1, void *d2), \
	void *data)
{
	t_node	*node;

	node = list->head;
	while (node != NULL)
	{
		if (compare(node->data, data) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	display_linked_list(t_linked_list *list, \
	void (*display)(t_linked_list *list))
{
	t_node	*current;

	current = list->head;
	while (current != NULL)
	{
		display(current);
		current = current->next;
	}
}
