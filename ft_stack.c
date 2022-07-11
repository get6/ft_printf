/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:15:00 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/11 13:49:55 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	initialize_stack(t_stack *stack)
{
	initialize_list(stack);
}

void	push(t_stack *stack, void *data)
{
	add_head(stack, data);
}

void	appendleft(t_stack *stack, void *data)
{
	add_tail(stack, data);
}

void	*pop(t_stack *stack)
{
	t_node	*node;
	void	*data;

	node = stack->head;
	if (node == NULL)
		return (NULL);
	else if (node == stack->tail)
	{
		stack->tail = NULL;
		stack->head = NULL;
		data = node->data;
		free(node);
		return (data);
	}
	else
	{
		stack->head = stack->head->next;
		data = node->data;
		free(node);
		return (data);
	}
}
