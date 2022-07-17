/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:54:24 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 11:43:54 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_usigned_decimal(t_counter *cnt)
{
	t_format		*fmt;
	unsigned int	arg;
	char			*str;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), int);
	fmt->value = (unsigned int *)malloc(sizeof(unsigned int));
	if (fmt->value == NULL)
		return ;
	*((unsigned int *)fmt->value) = arg;
	str = ft_putnbr_base(arg, "0123456789");
	if (str == NULL)
		return ;
	ft_replace_print_str(fmt, str);
}

void	ft_type_lower_hexadecimal(t_counter *cnt)
{
	t_format		*fmt;
	unsigned int	arg;
	char			*str;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), unsigned int);
	fmt->value = (unsigned int *)malloc(sizeof(unsigned int));
	if (fmt->value == NULL)
		return ;
	*((unsigned int *)fmt->value) = arg;
	str = ft_putnbr_base(arg, "0123456789abcdef");
	if (str == NULL)
		return ;
	ft_replace_print_str(fmt, str);
}

void	ft_type_upper_hexadecimal(t_counter *cnt)
{
	t_format		*fmt;
	unsigned int	arg;
	char			*str;

	fmt = cnt->fmt;
	arg = va_arg(*(cnt->ap), unsigned int);
	fmt->value = (unsigned int *)malloc(sizeof(unsigned int));
	if (fmt->value == NULL)
		return ;
	*((unsigned int *)fmt->value) = arg;
	str = ft_putnbr_base(arg, "0123456789ABCDEF");
	if (str == NULL)
		return ;
	ft_replace_print_str(fmt, str);
}

void	ft_type_percent(t_counter *cnt)
{
	t_format	*fmt;
	char		*str;

	fmt = cnt->fmt;
	fmt->value = (char *)malloc(1);
	if (fmt->value == NULL)
		return ;
	*((char *)fmt->value) = '%';
	str = ft_char_to_string('%');
	if (str == NULL)
		return ;
	ft_replace_print_str(fmt, str);
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
