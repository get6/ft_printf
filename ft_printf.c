/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:26:33 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/08 22:16:05 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * 찾고자 하는
*/
char	*ft_check_conversion(char *format)
{
	int		i;
	char	c;

	c = *format;
	i = 0;
	if ('c' == c)
		i = 1;
	else if ('s' == c)
		i = 1;
	else if ('p' == c)
		i = 1;
	else if ('d' == c)
		i = 1;
	else if ('i' == c)
		i = 1;
	else if ('u' == c)
		i = 1;
	else if ('x' == c)
		i = 1;
	else if ('X' == c)
		i = 1;
	return (NULL);
}

int	ft_get_format(const char *format)
{
	char	c;

	c = *format;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	char		c;
	int			i;
	va_list		ap;
	t_counter	*counter;
	t_operation	operations[128];

	if (format == NULL)
		return (0);
	counter = ft_counternew();
	i = 0;
	ft_initialize_operations_array(operations);
	va_start(ap, format);
	while (*(format + i) != '\0')
	{
		c = *(format + i);
		if (c == '%' && ft_check_conversion((char *)format + i) != NULL)
		{
			t_format *format = ft_
			i += ft_get_format((char *)format + i, );
			ft_evaluate_array(operations, i, )
		}
		else
			ft_putchar(c);
		i++;
	}
	va_end(ap);
	return (i);
}
