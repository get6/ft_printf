/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:15:30 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 15:28:45 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags(const char *str, t_format *fmt, t_operation *ops)
{
	unsigned char	c;

	c = ft_getchar(str, fmt);
	if (c != '\0' && ft_strchr("-+0 #", c) != NULL)
	{
		if (c == '-' && !fmt->option->flags->minus)
			fmt->option->flags->minus = 1;
		if (c == '+' && !fmt->option->flags->plus)
			fmt->option->flags->plus = 1;
		if (c == '0' && !fmt->option->flags->zero)
			fmt->option->flags->zero = 1;
		if (c == ' ' && !fmt->option->flags->blank)
			fmt->option->flags->blank = 1;
		if (c == '#' && !fmt->option->flags->sharp)
			fmt->option->flags->sharp = 1;
		push(fmt->operations, &ops[c]);
		*(fmt->index) += 1;
		ft_check_flags(str, fmt, ops);
	}
}

void	ft_check_width(const char *str, t_format *fmt, t_operation *ops)
{
	int		width;

	width = ft_get_width(str, fmt);
	fmt->option->width = width;
	if (width)
		push(fmt->operations, &ops['w']);
}

void	ft_check_precision(const char *str, t_format *fmt, t_operation *ops)
{
	char	c;

	c = ft_getchar(str, fmt);
	if (c != '\0' && c == '.')
	{
		*(fmt->index) += 1;
		fmt->option->precision = ft_get_precision(str, fmt);
		push(fmt->operations, &ops['.']);
	}
}

void	ft_check_type(const char *str, t_format *fmt, t_operation *ops)
{
	unsigned char	c;

	c = ft_getchar(str, fmt);
	fmt->type = c;
	*(fmt->index) += 1;
	if (c == 'c')
		push(fmt->operations, &ops['c']);
	else if (c == 's')
		push(fmt->operations, &ops['s']);
	else if (c == 'p')
		push(fmt->operations, &ops['p']);
	else if (c == 'd')
		push(fmt->operations, &ops['d']);
	else if (c == 'i')
		push(fmt->operations, &ops['i']);
	else if (c == 'u')
		push(fmt->operations, &ops['u']);
	else if (c == 'x')
		push(fmt->operations, &ops['x']);
	else if (c == 'X')
		push(fmt->operations, &ops['X']);
	else if (c == '%')
		push(fmt->operations, &ops['%']);
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		appendleft(fmt->operations, &ops['m']);
}
