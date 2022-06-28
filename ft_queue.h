/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:50:25 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/28 20:51:12 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include "ft_node.h"

// Queue
typedef t_linked_list	t_queue;

void	initialize_queue(t_queue *queue);
void	enqueue(t_queue *queue, void *node);
void	*dequeue(t_queue *queue);

#endif
