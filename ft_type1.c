/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:20 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 18:55:15 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_char(t_counter *cnt)
{
	t_format	*fmt;
	char		arg;
	char		*str;

	fmt = cnt->fmt;
	arg = (char)va_arg(*(cnt->ap), int);
	fmt->value = (char *)malloc(1);
	if (fmt->value == NULL)
		return ;
	*((char *)fmt->value) = arg;
	str = ft_char_to_string(arg);
	if (str == NULL)
		return ;
	ft_replace_print_str(&fmt, &str);
	fmt->length = !ft_is_nul(fmt);
}

void	ft_type_string(t_counter *cnt)
{
	t_format	*fmt;
	char		*arg;
	char		*str;

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
	str = ft_strdup(arg);
	if (str == NULL)
		return ;
	ft_replace_print_str(&fmt, &str);
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
	src = ft_putnbr_base((unsigned long long)arg, "0123456789abcdef");
	if (src == NULL)
		return ;
	src_len = ft_strlen(src);
	dst = (char *)malloc(src_len + 3);
	if (dst == NULL)
		return ;
	ft_memcpy(dst, "0x", 2);
	ft_strlcpy(dst + 2, src, src_len + 1);
	ft_safer_free((void **)&src);
	ft_replace_print_str(&fmt, &dst);
}

void	ft_type_decimal(t_counter *cnt)
{
	t_format	*fmt;
	int			arg;
	char		*str;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), int);
	fmt->value = (int *)malloc(sizeof(int));
	if (fmt->value == NULL)
		return ;
	*((int *)fmt->value) = arg;
	str = ft_delete_minus(arg);
	if (str == NULL)
		return ;
	ft_replace_print_str(&fmt, &str);
}

void	ft_type_integer(t_counter *cnt)
{
	t_format	*fmt;
	int			arg;
	char		*str;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), int);
	fmt->value = (int *)malloc(sizeof(int));
	if (fmt->value == NULL)
		return ;
	*((int *)fmt->value) = arg;
	str = ft_delete_minus(arg);
	if (str == NULL)
		return ;
	ft_replace_print_str(&fmt, &str);
}
