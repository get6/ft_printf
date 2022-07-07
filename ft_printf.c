/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:26:33 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/07 23:23:43 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_conversion(const char *str, t_format *fmt, t_operation *ops)
{
	ft_check_flags(str, fmt, ops);
	ft_check_width(str, fmt, ops);
	ft_check_precision(str, fmt, ops);
	ft_check_type(str, fmt, ops);
}

int	ft_check_total(t_counter *cnt, int length)
{
	if (cnt->total + length < 2147483647)
		cnt->total += length;
	else
	{
		cnt->total = -1;
		return (0);
	}
	return (1);
}

void	ft_loop_format(const char *str, t_counter *cnt, t_operation *ops)
{
	int			i;
	t_format	*fmt;

	i = cnt->total;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '%')
		{
			i++;
			fmt = ft_format_new();
			if (fmt == NULL)
				break ;
			fmt->index = &i;
			ft_check_conversion(str, fmt, ops);
			ft_get_format(cnt, fmt, ops);
			if (ft_check_total(cnt, fmt->length))
			{
				ft_putstr((char *)fmt->print);
				ft_safer_free((void **)&fmt);
				continue ;
			}
			else
			{
				ft_safer_free((void **)&fmt);
				break ;
			}
		}
		else
			if (ft_check_total(cnt, 1))
				ft_putchar(*(str + i));
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int			res;
	va_list		ap;
	t_counter	*cnt;
	t_operation	operations[128];

	if (format == NULL)
		return (0);
	va_start(ap, format);
	cnt = ft_counter_new(ap);
	if (cnt == NULL)
		return (-1);
	ft_initialize_operations_array(operations);
	ft_loop_format(format, cnt, operations);
	va_end(ap);
	res = cnt->total;
	ft_safer_free((void **)&cnt);
	return (res);
}
