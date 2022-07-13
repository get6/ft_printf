/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:20 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/13 21:55:00 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_char(t_counter *cnt)
{
	t_format	*fmt;
	char		arg;

	fmt = cnt->fmt;
	arg = (char)va_arg(*(cnt->ap), int);
	fmt->value = (char *)malloc(1);
	if (fmt->value == NULL)
		return ;
	*((char *)fmt->value) = arg;
	fmt->print = ft_char_to_string(arg);
	if (fmt->print == NULL)
		return ;
	fmt->length = !ft_is_nul(fmt);
}

void	ft_type_string(t_counter *cnt)
{
	t_format	*fmt;
	char		*arg;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), char *);
	if (arg == NULL)
	{
		arg = "(null)";
		fmt->value = NULL;
	}
	else
	{
		fmt->value = ft_strdup(arg);
		if (fmt->value == NULL)
			return ;
	}
	fmt->print = ft_strdup(arg);
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_pointer(t_counter *cnt)
{
	t_format			*fmt;
	unsigned long long	arg;
	char				*dst;
	char				*src;
	int					src_len;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), unsigned long long);
	fmt->value = (unsigned long long *)malloc(sizeof(unsigned long long));
	if (fmt->value == NULL)
		return ;
	*((unsigned long long *)fmt->value) = arg;
	src = ft_putnbr_base(arg, "0123456789abcdef");
	if (src == NULL)
		return ;
	src_len = ft_strlen(src) + 2;
	dst = (char *)malloc(src_len);
	if (dst == NULL)
		return ;
	ft_memcpy(dst, "0x", 3);
	ft_strlcat(dst + 2, src, src_len);
	fmt->print = dst;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_decimal(t_counter *cnt)
{
	t_format	*fmt;
	int			arg;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), int);
	fmt->value = (int *)malloc(sizeof(int));
	if (fmt->value == NULL)
		return ;
	*((int *)fmt->value) = arg;
	fmt->print = ft_delete_minus(arg);
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}

void	ft_type_integer(t_counter *cnt)
{
	t_format	*fmt;
	int			arg;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), int);
	fmt->value = (int *)malloc(sizeof(int));
	if (fmt->value == NULL)
		return ;
	*((int *)fmt->value) = arg;
	fmt->print = ft_delete_minus(arg);
	if (fmt->print == NULL)
		return ;
	fmt->length = ft_strlen(fmt->print);
}
