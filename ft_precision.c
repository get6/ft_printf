/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:15 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/07 22:48:04 by sunhwang         ###   ########.fr       */
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
	return (ft_atoi(str));
}


void	ft_calc_precision(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

