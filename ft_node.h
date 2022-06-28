/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:06:39 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/28 20:54:52 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_H
# define FT_NODE_H

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
}	t_node;

// LinkedList
typedef struct s_linked_list
{
	t_node	*head;
	t_node	*tail;
	t_node	*current;
}	t_linked_list;

void	initialize_list(t_linked_list *list);
void	add_head(t_linked_list *list, void *data);
void	add_tail(t_linked_list *list, void *data);
void	delete_node(t_linked_list *list, t_node *node);
t_node	*get_node(t_linked_list *list, int (*compare)(void *d1, void *d2), \
	void *data);
void	display_linked_list(t_linked_list *list, \
	void (*display)(t_linked_list *list));

#endif
