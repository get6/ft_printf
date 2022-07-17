/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:26:33 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 18:33:34 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_char(t_format *fmt)
{
	if (fmt->option->flags->minus)
	{
		ft_putchar(*((char *)fmt->value));
		ft_putstr(fmt->print);
	}
	else
	{
		ft_putstr(fmt->print);
		ft_putchar(*((char *)fmt->value));
	}
}

static int	ft_check_total(t_counter *cnt, int length)
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

static int	ft_handle_format(const char *str, t_counter *cnt, \
t_operation *ops)
{
	int			res;
	t_format	*fmt;

	res = 0;
	fmt = cnt->fmt;
	ft_check_flags(str, fmt, ops);
	ft_check_width(str, fmt, ops);
	ft_check_precision(str, fmt, ops);
	ft_check_type(str, fmt, ops);
	ft_get_format(cnt);
	if (ft_check_total(cnt, fmt->length))
	{
		res = 1;
		if (ft_is_same_type(fmt, 'c') && *((char *)fmt->value) == '\0')
		{
			ft_check_total(cnt, 1);
			ft_print_char(fmt);
		}
		else
			ft_putstr(fmt->print);
	}
	ft_format_free(&(cnt->fmt));
	return (res);
}

static void	ft_loop_format(const char *str, t_counter *cnt, t_operation *ops)
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
			cnt->fmt = fmt;
			if (ft_handle_format(str, cnt, ops))
				continue ;
			else
				break ;
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
	cnt = ft_counter_new(&ap);
	if (cnt == NULL)
		return (-1);
	ft_initialize_operations_array(operations);
	ft_loop_format(format, cnt, operations);
	va_end(ap);
	res = cnt->total;
	ft_safer_free((void **)&cnt);
	return (res);
}
