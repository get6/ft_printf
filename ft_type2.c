/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:54:24 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/07 22:54:19 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_usigned_decimal(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

void	ft_type_lower_hexadecimal(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

void	ft_type_upper_hexadecimal(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	(void)fmt;
}

void	ft_type_percent(t_counter *cnt, t_format *fmt)
{
	char	arg;
	va_list	ap;

	ap = cnt->ap;
	arg = (char)va_arg(ap, int);
	fmt->print = ft_char_to_string(arg);
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

char	*ft_char_to_string(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, &c, sizeof(char));
	*(str + 1) = '\0';
	return (str);
}
