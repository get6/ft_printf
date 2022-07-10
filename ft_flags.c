/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:12 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/09 19:41:07 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_minus(t_counter *cnt, t_format *fmt)
{
	int		length;
	int		start;
	char	*str;

	(void)cnt;
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
	int		i;
	char	c;

	(void)cnt;
	i = 0;
	if (fmt->option->precision)
		i = fmt->option->width - fmt->option->precision;
	while (*(fmt->print + i) != '\0')
	{
		c = *(fmt->print + i);
		if (c == ' ')
			*(fmt->print + i) = '0';
		else
			break ;
		i++;
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

void	ft_flag_plus(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}
