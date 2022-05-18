/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:26:33 by sunhwang          #+#    #+#             */
/*   Updated: 2022/05/18 19:37:54 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	// int		i;
	char	*arg;
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, format);
	while (format != NULL)
	{
		arg = va_arg(ap, char *);
		format++;
	}
	va_end(ap);
	return (res);
}
