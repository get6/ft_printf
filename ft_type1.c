/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:20 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/07 22:37:32 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char 리터럴은 int형태임 sizeof('a') == 4
void	ft_type_char(t_counter *cnt, t_format *fmt)
{
	va_list	ap;
	char	arg;

	ap = cnt->ap;
	arg = (char)va_arg(ap, int);
	fmt->value = ft_char_to_string(arg);
	if (fmt->value == NULL)
		return ;
	fmt->print = ft_char_to_string(arg);
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_string(t_counter *cnt, t_format *fmt)
{
	char	*arg;
	va_list	ap;

	ap = cnt->ap;
	arg = va_arg(ap, char *);
	fmt->value = (char *)malloc(sizeof(char) * ft_strlen(arg));
	if (fmt->value == NULL)
		return ;
	ft_strlcpy(fmt->value, arg, sizeof(arg));
	fmt->print = (char *)malloc(sizeof(char) * ft_strlen(arg));
	if (fmt->print == NULL)
		return ;
	ft_strlcpy(fmt->print, arg, sizeof(arg));
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_pointer(t_counter *cnt, t_format *fmt)
{
	int		arg;
	va_list	ap;

	ap = cnt->ap;
	arg = va_arg(ap, long long);
	fmt->value = (long long *)malloc(sizeof(long long));
	if (fmt->value == NULL)
		return ;
	ft_memcpy(fmt->value, &arg, sizeof(long long *));
	// TODO 0x 추가해줘야 하눈디...
	fmt->print = ft_itoa(arg);
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_decimal(t_counter *cnt, t_format *fmt)
{
	int		arg;
	va_list	ap;

	ap = cnt->ap;
	arg = va_arg(ap, int);
	fmt->print = ft_itoa(arg);
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_integer(t_counter *cnt, t_format *fmt)
{
	int		arg;
	va_list	ap;

	ap = cnt->ap;
	arg = va_arg(ap, int);
	fmt->print = ft_itoa(arg);
	fmt->length = ft_strlen(fmt->print);
}


