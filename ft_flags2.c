/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:15:38 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 15:43:03 by sunhwang         ###   ########.fr       */
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
	ft_replace_print_str(&fmt, &str);
}

static	int	ft_find_blank(t_format *fmt)
{
	int	i;
	int	find_digit;

	i = 0;
	find_digit = 0;
	while (!find_digit && *(fmt->print + i) != '\0')
	{
		if (ft_isdigit(*(fmt->print + i)))
			find_digit = 1;
		else if (!find_digit && *(fmt->print + i) == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_flag_blank(t_counter *cnt)
{
	t_format	*fmt;
	char		*str;

	fmt = cnt->fmt;
	if (!fmt->option->flags->blank || fmt->option->flags->plus \
	|| ft_is_minus(fmt))
		return ;
	if (ft_find_blank(fmt))
		return ;
	str = (char *)malloc(fmt->length + 1);
	if (str == NULL)
		return ;
	if (fmt->option->flags->minus)
	{
		str = (char *)malloc(fmt->length + 2);
		if (str == NULL)
			return ;
		*str = ' ';
		ft_strlcpy(str + 1, fmt->print, fmt->length + 1);
		if (*(str + fmt->length) == ' ')
			*(str + fmt->length) = '\0';
	}
	else
		str = ft_copy_str_with_flag(fmt->print, ' ', fmt->length);
	ft_replace_print_str(&fmt, &str);
}
