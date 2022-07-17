/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:14:58 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 12:38:19 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "ft_node.h"

void	initialize_stack(t_stack *stack);
void	push(t_stack *stack, void *data);
void	appendleft(t_stack *stack, void *data);
void	*pop(t_stack *stack);

#endif
