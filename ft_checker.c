/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:15:30 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/05 21:58:36 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags(const char *str, t_format *fmt, t_operation *ops)
{
	unsigned char	c;

	c = *(str + (*(fmt->index)));
	if (c != '\0' && ft_strchr("-+0 #", c) != NULL)
	{
		// TODO 일단 중복되게 넣어보고 문제가 되면 검증하는 로직 추가
		if (c == '-')
			fmt->option->flags->minus = 1;
		else if (c == '+')
			fmt->option->flags->plus = 1;
		else if (c == '0')
			fmt->option->flags->zero = 1;
		else if (c == ' ')
			fmt->option->flags->blank = 1;
		else if (c == '#')
			fmt->option->flags->sharp = 1;
		push(fmt->operations, ops[c]);
		*(fmt->index) += 1;
		ft_check_flags(str, fmt, ops);
	}
}

void	ft_check_width(const char *str, t_format *fmt, t_operation *ops)
{
	char	c;
	int		width;

	c = *str;
	width = 0;
	fmt->option->width = 1;
	// TODO 0 부터 시작되는건 flag다.
	// if (c != '\0' && (c != '0' && ft_isdigit(c)))
	if (c != '\0' && ft_isdigit(c))
		width = ft_get_width((char *)str);
	if (!width)
		width = ft_strlen(fmt->value);
	push(fmt->operations, ops['w']);
}

void	ft_check_precision(const char *str, t_format *fmt, t_operation *ops)
{
	char	c;

	c = *str;
	if (c != '\0' && c == '.')
	{
		fmt->option->precision = ft_get_precision(str + 1);
		push(fmt->operations, ops['.']);
	}
}

void	ft_check_type(const char *str, t_format *fmt, t_operation *ops)
{
	unsigned char	c;

	c = *str;
	fmt->type = c;
	push(fmt->operations, ops[c]);
	// if (c == 'c')
	// 	push(fmt->operations, ops['c']);
	// else if (c == 's')
	// 	push(fmt->operations, ops['s']);
	// else if (c == 'p')
	// 	push(fmt->operations, ops['p']);
	// else if (c == 'd')
	// 	push(fmt->operations, ops['d']);
	// else if (c == 'i')
	// 	push(fmt->operations, ops['i']);
	// else if (c == 'u')
	// 	push(fmt->operations, ops['u']);
	// else if (c == 'x')
	// 	push(fmt->operations, ops['x']);
	// else if (c == 'X')
	// 	push(fmt->operations, ops['X']);
	// else if (c == '%')
	// 	push(fmt->operations, ops['%']);
}
