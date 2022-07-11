/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:28:23 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/11 13:10:59 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_operations_array(t_operation *ops)
{
	int	i;

	i = 0;
	while (i < 128)
		ops[i++] = NULL;
	ops['c'] = ft_type_char;
	ops['s'] = ft_type_string;
	ops['p'] = ft_type_pointer;
	ops['d'] = ft_type_decimal;
	ops['i'] = ft_type_integer;
	ops['u'] = ft_type_usigned_decimal;
	ops['x'] = ft_type_lower_hexadecimal;
	ops['X'] = ft_type_upper_hexadecimal;
	ops['%'] = ft_type_percent;
	ops['-'] = ft_flag_minus;
	ops['0'] = ft_flag_zero;
	ops['.'] = ft_calc_precision;
	ops['#'] = ft_flag_sharp;
	ops[' '] = ft_flag_blank;
	ops['+'] = ft_flag_plus;
	ops['w'] = ft_calc_width;
	ops['m'] = ft_calc_minus;
}

// TODO 함께 쓰이는 플래그들 처리하는 용도
static void	ft_check_operation(t_counter *cnt, t_format *fmt, t_operation *op)
{
	(*op)(cnt, fmt);
}

void	ft_get_format(t_counter *cnt, t_format *fmt)
{
	t_operation	*op;

	while (fmt->operations->head != NULL)
	{
		op = (t_operation *)pop(fmt->operations);
		if (op == NULL)
			break ;
		ft_check_operation(cnt, fmt, op);
	}
}
