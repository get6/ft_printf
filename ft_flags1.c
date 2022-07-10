/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:12 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/10 22:38:42 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_minus(t_counter *cnt, t_format *fmt)
{
	int		length;
	int		start;
	char	*str;

	(void)cnt;
	if (ft_is_nul(fmt))
		return ;
	length = ft_strlen(fmt->print);
	str = (char *)malloc(length + 1);
	if (str == NULL)
		return ;
	start = 0;
	while (*(fmt->print + start) != '\0')
	{
		if (*(fmt->print + start) == ' ')
			start++;
		else
			break ;
	}
	ft_memset(str, ' ', length);
	ft_memcpy(str, fmt->print + start, ft_strlen(fmt->print + start));
	*(str + length) = '\0';
	free(fmt->print);
	fmt->print = str;
}

void	ft_flag_zero(t_counter *cnt, t_format *fmt)
{
	int		neg;
	int		i;
	char	c;

	if (fmt->option->flags->minus)
		return ;
	(void)cnt;
	neg = ft_is_negative(fmt);
	i = 0;
	if (fmt->option->precision)
		i = fmt->option->width - fmt->option->precision;
	while (*(fmt->print + i + neg) != '\0')
	{
		c = *(fmt->print + i + neg);
		if (c == ' ')
			*(fmt->print + i + neg) = '0';
		else
			break ;
		i++;
	}
	if (neg)
	{
		*(fmt->print + i + neg) = '0';
		*(fmt->print) = '-';
	}
}

void	ft_flag_sharp(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

void	ft_flag_blank(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

