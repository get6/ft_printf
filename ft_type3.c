/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:05 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/11 13:20:44 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_same_type(t_format *fmt, char c)
{
	return (fmt->type == c);
}

int	ft_is_nul(t_format *fmt)
{
	return (ft_is_same_type(fmt, 'c') && *(char *)fmt->value == '\0');
}

void	ft_calc_minus(t_counter *cnt, t_format *fmt)
{
	if (!ft_is_minus(fmt))
		return ;
	(void)cnt;
}
