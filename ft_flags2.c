/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:15:38 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/13 21:54:28 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_plus(t_counter *cnt)
{
	t_format	*fmt;
	char		*str;

	fmt = cnt->fmt;
	if (!fmt->option->flags->plus || ft_is_minus(fmt))
		return ;
	if (fmt->option->flags->minus)
	{
		str = (char *)malloc(fmt->length + 2);
		if (str == NULL)
			return ;
		*str = '+';
		ft_strlcpy(str + 1, fmt->print, fmt->length + 1);
	}
	else
		str = ft_copy_str_with_flag(fmt->print, '+', fmt->length);
	if (str == NULL)
		return ;
	ft_replace_print_str(fmt, str);
}
