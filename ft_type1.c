/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:20 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/09 23:02:49 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_char(t_counter *cnt, t_format *fmt)
{
	char	arg;

	arg = (char)va_arg(*(cnt->ap), int);
	if (arg == '\0')
		ft_putchar(arg);
	fmt->print = ft_char_to_string(arg);
	fmt->length = ft_strlen(fmt->print);
}

void	ft_set_null(t_format *fmt)
{
	char	*null;

	null = "(null)";
	fmt->print = (char *)malloc(ft_strlen(null));
	if (fmt->print == NULL)
		return ;
	ft_strlcpy(fmt->print, null, ft_strlen(null));
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_string(t_counter *cnt, t_format *fmt)
{
	char	*arg;
	int		arg_len;

	arg = va_arg(*(cnt->ap), char *);
	if (arg == NULL)
	{
		ft_set_null(fmt);
		return ;
	}
	arg_len = ft_strlen(arg);
	fmt->print = (char *)malloc(arg_len + 1);
	if (fmt->print == NULL)
		return ;
	ft_strlcpy(fmt->print, arg, arg_len + 1);
	fmt->length = ft_strlen(fmt->print);
}

// TODO 0x 추가해줘야 하눈디...
void	ft_type_pointer(t_counter *cnt, t_format *fmt)
{
	int		arg;

	arg = va_arg(*(cnt->ap), long long);
	fmt->print = ft_itoa(arg);
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_decimal(t_counter *cnt, t_format *fmt)
{
	int		arg;

	arg = va_arg(*(cnt->ap), int);
	fmt->print = ft_itoa(arg);
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_integer(t_counter *cnt, t_format *fmt)
{
	int		arg;

	arg = va_arg(*(cnt->ap), int);
	fmt->print = ft_itoa(arg);
	fmt->length = ft_strlen(fmt->print);
}
