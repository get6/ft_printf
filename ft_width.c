/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:22 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/13 21:55:18 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_width(const char *str, t_format *fmt)
{
	char	c;
	int		width;

	width = 0;
	while (ft_getchar(str, fmt) != '\0')
	{
		c = ft_getchar(str, fmt);
		if (ft_isdigit(c))
			width = width * 10 + (c - '0');
		else
			break ;
		*(fmt->index) += 1;
	}
	return (width);
}

void	ft_ajdust_width(t_format *fmt)
{
	if (!fmt->option->width)
		fmt->option->width = fmt->length;
	if (ft_is_nul(fmt))
		fmt->option->width--;
	if (ft_is_minus(fmt))
		fmt->option->width--;
	else if (fmt->option->flags->plus)
		fmt->option->width--;
}

void	ft_calc_width(t_counter *cnt)
{
	t_format	*fmt;
	int			width;
	int			length;
	char		*str;

	fmt = cnt->fmt;
	ft_ajdust_width(fmt);
	width = fmt->option->width;
	length = fmt->length;
	if (width < length)
		width = length;
	str = (char *)malloc(width + 1);
	if (str == NULL)
		return ;
	ft_memset(str, ' ', width);
	ft_memcpy(str + (width - length), fmt->print, length);
	*(str + width) = '\0';
	ft_replace_print_str(fmt, str);
}
