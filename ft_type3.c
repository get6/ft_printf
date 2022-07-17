/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:05 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 10:44:04 by sunhwang         ###   ########.fr       */
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

void	ft_calc_minus(t_counter *cnt)
{
	t_format	*fmt;
	char		*str;

	fmt = cnt->fmt;
	if (!ft_is_minus(fmt))
		return ;
	str = ft_copy_str_with_flag(fmt->print, '-', fmt->length);
	if (str == NULL)
		return ;
	fmt->option->width += 1;
	fmt->option->empty_width -= 1;
	ft_replace_print_str(fmt, str);
}
