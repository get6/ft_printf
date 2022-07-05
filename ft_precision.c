/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:15 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/05 21:05:13 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_precision(const char *str)
{
	return (ft_atoi(str));
}


void	ft_calc_precision(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

