/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:26:33 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/28 21:13:03 by sunhwang         ###   ########.fr       */
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

void	ft_loop_format(const char *format, va_list ap, \
t_counter *counter, t_operation *operations)
{
	char	c;
	int		i;

	i = counter->total;
	while (*(format + i) != '\0')
	{
		c = *(format + i);
		if (c == '%' && ft_check_conversion((char *)format + i) != NULL)
		{

			format = ft_formatnew();
			if (format == NULL)
				break ;
			// i += ft_get_format((char *)format + i, );
			// ft_evaluate_array(operations, i, )
		}
		else
			ft_putchar(c);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_counter	*counter;
	t_operation	operations[128];

	if (format == NULL)
		return (0);
	counter = ft_counternew();
	if (counter == NULL)
		return (-1);
	initialize_queue(counter->head);
	ft_initialize_operations_array(operations);
	va_start(ap, format);
	ft_loop_format(format, ap, counter, operations);
	va_end(ap);
	return (counter->total);
}
