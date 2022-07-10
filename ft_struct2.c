/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:34:05 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/09 19:36:39 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_operations_free(t_format *fmt)
{
	t_operation	*op;

	while (fmt->operations->head != NULL)
	{
		op = (t_operation *)pop(fmt->operations);
		if (op != NULL)
			ft_safer_free((void **)&op);
	}
}

void	ft_format_free(t_format *fmt)
{
	if (fmt == NULL)
		return ;
	if (fmt->print != NULL)
		ft_safer_free((void **)&fmt->print);
	if (fmt->option != NULL)
	{
		ft_safer_free((void **)&fmt->option->flags);
		ft_safer_free((void **)&fmt->option);
	}
	if (fmt->operations != NULL)
		ft_operations_free(fmt);
	ft_safer_free((void **)&fmt);
}
