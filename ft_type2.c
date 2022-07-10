/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:54:24 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/09 22:18:49 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_usigned_decimal(t_counter *cnt, t_format *fmt)
{
	int	arg;

	arg = va_arg(*(cnt->ap), int);
	fmt->print = ft_putnbr_base(arg, "0123456789");
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_lower_hexadecimal(t_counter *cnt, t_format *fmt)
{
	int	arg;

	arg = va_arg(*(cnt->ap), int);
	fmt->print = ft_putnbr_base(arg, "0123456789abcdef");
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_upper_hexadecimal(t_counter *cnt, t_format *fmt)
{
	int	arg;

	arg = va_arg(*(cnt->ap), int);
	fmt->print = ft_putnbr_base(arg, "0123456789ABCDEF");
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_percent(t_counter *cnt, t_format *fmt)
{
	(void)cnt;
	fmt->print = ft_char_to_string('%');
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

char	*ft_char_to_string(char c)
{
	char	*str;

	str = (char *)malloc(2);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, &c, 2);
	*(str + 1) = '\0';
	return (str);
}
