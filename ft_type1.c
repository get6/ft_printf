/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:20 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/05 21:27:23 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char 리터럴은 int형태임 sizeof('a') == 4
void	ft_type_char(t_counter *cnt, t_format *fmt)
{
	va_list	ap;
	char	arg;

	ap = cnt->ap;
	arg = (char)va_arg(ap, int);
	fmt->value = &arg;
}

void	ft_type_string(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

void	ft_type_pointer(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

void	ft_type_decimal(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

void	ft_type_integer(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}


