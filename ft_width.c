/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:22 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/07 22:43:57 by sunhwang         ###   ########.fr       */
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

void	ft_calc_width(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}
