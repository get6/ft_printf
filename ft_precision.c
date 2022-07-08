/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:15 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/08 15:15:08 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_precision(const char *str, t_format *fmt)
{
	char	c;
	int		precision;

	precision = 0;
	while (ft_getchar(str, fmt) != '\0')
	{
		c = ft_getchar(str, fmt);
		if (ft_isdigit(c))
			precision = precision * 10 + (c - '0');
		else
			break ;
		*(fmt->index) += 1;
	}
	return (precision);
}

void	ft_precision_string(t_format *fmt)
{
	int		precision;
	int		length;
	char	*str;

	precision = fmt->option->precision;
	length = ft_strlen(fmt->print);
	if (precision < length)
	{
		str = (char *)malloc(sizeof(char) * (precision + 1));
		if (str == NULL)
			return ;
		ft_strlcpy(str, fmt->print, precision + 1);
		free(fmt->print);
		fmt->print = str;
	}
}

void	ft_precision_number(t_format *fmt)
{
	int		precision;
	int		length;
	char	*str;

	precision = fmt->option->precision;
	length = ft_strlen(fmt->print);
	if (length < precision)
	{
		str = (char *)malloc(sizeof(char) * (precision + 1));
		if (str == NULL)
			return ;
		ft_memset(str, '0', precision);
		ft_memcpy(str + (precision - length), fmt->print, length);
		*(str + precision) = '\0';
		free(fmt->print);
		fmt->print = str;
	}
}

void	ft_calc_precision(t_counter *cnt, t_format *fmt)
{

	(void)cnt;
	if (ft_is_same_type(fmt, 's'))
		ft_precision_string(fmt);
	else if (ft_is_same_type(fmt, 'd') || ft_is_same_type(fmt, 'i') \
	|| ft_is_same_type(fmt, 'u') || ft_is_same_type(fmt, 'x') \
	|| ft_is_same_type(fmt, 'X'))
		ft_precision_number(fmt);
	else
		fmt->option->precision = -1;
}

