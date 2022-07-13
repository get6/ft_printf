/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:12 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/13 21:53:58 by sunhwang         ###   ########.fr       */
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
	int			length;
	int			start;
	char		*str;

	fmt = cnt->fmt;
	if (!fmt->option->flags->minus || ft_is_nul(fmt))
		return ;
	length = ft_strlen(fmt->print);
	str = (char *)malloc(length + 1);
	if (str == NULL)
		return ;
	start = 0;
	while (*(fmt->print + start) != '\0')
	{
		if (*(fmt->print + start) == ' ')
			start++;
		else
			break ;
	}
	ft_memset(str, ' ', length);
	ft_memcpy(str, fmt->print + start, ft_strlen(fmt->print + start));
	*(str + length) = '\0';
	ft_replace_print_str(fmt, str);
}

void	ft_flag_zero(t_counter *cnt)
{
	t_format	*fmt;
	int			i;
	char		c;

	fmt = cnt->fmt;
	if (!fmt->option->flags->zero || fmt->option->flags->minus)
		return ;
	i = 0;
	if (fmt->option->flags->blank && !ft_is_minus(fmt))
		i = 1;
	if (fmt->option->precision)
		i = fmt->option->width - fmt->option->precision;
	while (*(fmt->print + i) != '\0')
	{
		c = *(fmt->print + i);
		if (c == ' ')
			*(fmt->print + i) = '0';
		else
			break ;
		i++;
	}
}

void	ft_flag_sharp(t_counter *cnt)
{
	t_format	*fmt;

	fmt = cnt->fmt;
}

static	int	ft_find_blank(t_format *fmt)
{
	int	i;
	int	find_digit;
	int	find_blank;

	i = 0;
	find_digit = 0;
	find_blank = 0;
	while (*(fmt->print + i) != '\0')
	{
		if (ft_isdigit(*(fmt->print + i)))
			find_digit = 1;
		else if (!find_digit && *(fmt->print + i) == ' ')
		{
			find_blank = 1;
			break ;
		}
		i++;
	}
	return (find_blank);
}

void	ft_flag_blank(t_counter *cnt)
{
	t_format	*fmt;
	char		*str;
	int			i;

	fmt = cnt->fmt;
	if (!fmt->option->flags->blank || ft_is_minus(fmt))
		return ;
	if (ft_find_blank(fmt))
		return ;
	str = (char *)malloc(fmt->length + 1);
	if (str == NULL)
		return ;
	i = 0;
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
