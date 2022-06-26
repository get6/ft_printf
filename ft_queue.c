/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:59:11 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/25 18:08:30 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_node.h"

void	initialize_queue(t_queue *queue)
{
	initialize_list(queue);
}

void	enqueue(t_queue *queue, void *node)
{
	add_head(queue, node);
}

void	*dequeue(t_queue *queue)
{
	t_node	*tmp;
	void	*data;

	tmp = queue->head;
	if (queue->head == NULL)
		data = NULL;
	else if (queue->head == queue->tail)
	{
		queue->tail = NULL;
		queue->head = NULL;
		data = tmp->data;
		free(tmp);
	}
	else
	{
		while (tmp->next != queue->tail)
			tmp = tmp->next;
		queue->tail = tmp;
		tmp = tmp->next;
		queue->tail->next = NULL;
		data = tmp->data;
		free(tmp);
	}
	return (data);
}
