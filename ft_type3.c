/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:05 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/10 17:58:56 by sunhwang         ###   ########.fr       */
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