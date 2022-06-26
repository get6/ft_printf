/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:28:23 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/08 22:19:11 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_test(t_format node)
{
	return ;
}

void	ft_initialize_operations_array(t_operation *operations)
{
	operations[D_CHARACTER] = ft_test;
	operations[D_STRING] = ft_test;
	operations[D_POINTER] = ft_test;
	operations[D_DECIMAL] = ft_test;
	operations[D_INTEGER] = ft_test;
	operations[D_UN_DECIMAL] = ft_test;
	operations[D_LOWER_HEXA] = ft_test;
	operations[D_UPPER_HEXA] = ft_test;
	operations[D_PERCENT] = ft_test;
	operations[D_MINUS] = ft_test;
	operations[D_ZERO] = ft_test;
	operations[D_DOT] = ft_test;
	operations[D_SHARP] = ft_test;
	operations[D_BLANK] = ft_test;
	operations[D_PLUS] = ft_test;
}

t_format	ft_evaluate_array(t_operation *operations, t_format *format)
{
	t_operation	operation;

	operation = operations[format->flags];
	return (operation(format, format->value));
}

// char 리터럴은 int형태임 sizeof('a') == 4
void	ft_format_c(va_list ap, t_format *format)
{
	char	arg;

	arg = (char)va_arg(ap, int);
	format->value = &arg;
}
