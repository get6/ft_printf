/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:06:09 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/11 13:59:01 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		list->tail->next = node;
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
