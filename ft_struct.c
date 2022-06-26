/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:34:05 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/26 20:03:55 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_counter	*ft_counternew(void)
{
	t_counter	*new;

	new = (t_format *)malloc(sizeof(t_counter));
	new->total = 0;
	new->length = 0;
	new->head = NULL;
	return (new);
}

t_format	*ft_formatnew(void)
{
	t_format	*new;

	new = (t_format *)malloc(sizeof(t_format));
	new->flags = NULL;
	return (new);
}
