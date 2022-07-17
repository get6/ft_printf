/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:01:12 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 15:43:03 by sunhwang         ###   ########.fr       */
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
	ft_replace_print_str(&fmt, &str);
}

static int	ft_do_while_black_to_zero(t_format *fmt, int i)
{
	int	did_while;

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
	return (did_while);
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
	did_while = ft_do_while_black_to_zero(fmt, i);
	zeros = ft_get_char_count_from_start(fmt->print, '0');
	if (zeros && did_while)
		fmt->option->empty_width -= zeros;
}
