/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:34:05 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 12:41:44 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_operations_free(t_format *fmt)
{
	t_operation	*op;

	while (fmt->operations->head != NULL)
	{
		op = (t_operation *)pop(fmt->operations);
		if (op != NULL)
			ft_safer_free((void **)&op);
	}
}

void	ft_format_free(t_format **p_fmt)
{
	t_format	*fmt;

	fmt = *p_fmt;
	if (fmt == NULL)
		return ;
	if (fmt->value != NULL)
		ft_safer_free((void **)&fmt->value);
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
