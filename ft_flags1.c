/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:12 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 11:51:35 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_copy_str_with_flag(const char *src, char flag, int length)
{
	char	c;
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(length + 1);
	if (str == NULL)
		return (NULL);
	while (*(src + i) != '\0')
	{
		c = *(src + i);
		if (ft_isdigit(c))
			break ;
		*(str + i) = c;
		i++;
	}
	*(str + i) = flag;
	ft_strlcpy(str + 1 + i, src + i, length + 1);
	return (str);
}

void	ft_flag_minus(t_counter *cnt)
{
	t_format	*fmt;
	char		*str;
	int			length;
	int			i;

	fmt = cnt->fmt;
	if (!fmt->option->flags->minus || ft_is_nul(fmt))
		return ;
	length = ft_strlen(fmt->print);
	str = (char *)malloc(length + 1);
	if (str == NULL)
		return ;
	i = ft_get_char_count_from_start(fmt->print, ' ');
	ft_memset(str, ' ', length);
	ft_memcpy(str, fmt->print + i, ft_strlen(fmt->print + i));
	*(str + length) = '\0';
	ft_replace_print_str(fmt, str);
}

void	ft_flag_zero(t_counter *cnt)
{
	t_format	*fmt;
	int			i;
	int			zeros;
	int			did_while;

	fmt = cnt->fmt;
	if (!fmt->option->flags->zero || fmt->option->flags->minus)
		return ;
	i = 0;
	if (!fmt->option->flags->plus && fmt->option->flags->blank && \
	!ft_is_minus(fmt))
		i = 1;
	if (fmt->option->precision)
	{
		i = fmt->option->width - fmt->option->precision;
		if (i < 0)
			i = 0;
	}
	did_while = 0;
	while (*(fmt->print + i) != '\0')
	{
		if (*(fmt->print + i) == ' ')
		{
			*(fmt->print + i) = '0';
			did_while++;
		}
		else
			break ;
		i++;
	}
	zeros = ft_get_char_count_from_start(fmt->print, '0');
	if (zeros && did_while)
		fmt->option->empty_width -= zeros;
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
	ft_replace_print_str(fmt, str);
}
