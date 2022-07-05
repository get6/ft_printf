/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:06:39 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/05 21:24:48 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_H
# define FT_NODE_H

# include "ft_struct.h"

void	initialize_list(t_linked_list *list);
void	add_head(t_linked_list *list, void *data);
void	add_tail(t_linked_list *list, void *data);
void	delete_node(t_linked_list *list, t_node *node);
t_node	*get_node(t_linked_list *list, int (*compare)(void *d1, void *d2), \
	void *data);

#endif
