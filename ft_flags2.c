/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:15:38 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 11:18:55 by sunhwang         ###   ########.fr       */
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
	ft_replace_print_str(fmt, str);
}

static char	*ft_get_sharp(t_format *fmt)
{
	char		*str;

	if (fmt->type == 'x')
		str = ft_strdup("0x");
	else
		str = ft_strdup("0X");
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	*ft_sharp_minus(t_format *fmt, char *sharp)
{
	char	*str;
	int		sharp_len;

	sharp_len = ft_strlen(sharp);
	if (fmt->option->empty_width < sharp_len)
	{
		str = (char *)malloc(fmt->length + sharp_len \
		- fmt->option->empty_width);
		ft_memcpy(str, sharp, sharp_len);
		ft_strlcpy(str + sharp_len, fmt->print, fmt->length + 1 \
		- fmt->option->empty_width);
	}
	else
	{
		ft_memmove(fmt->print + sharp_len, fmt->print, fmt->length - sharp_len);
		ft_memmove(fmt->print, sharp, sharp_len);
		str = ft_strdup(fmt->print);
	}
	return (str);
}

static char	*ft_sharp_plus(t_format *fmt, char *sharp)
{
	char	*str;
	int		i;
	int		sharp_len;

	sharp_len = ft_strlen(sharp);
	i = ft_get_char_count_from_start(fmt->print, ' ');
	if (fmt->option->empty_width < sharp_len)
	{
		str = (char *)malloc(fmt->length + sharp_len \
		- fmt->option->empty_width);
		ft_memcpy(str, sharp, sharp_len);
		ft_strlcpy(str + sharp_len, fmt->print + i, fmt->length + 1 - i);
	}
	else
	{
		ft_memmove(fmt->print + i - sharp_len, sharp, sharp_len);
		str = ft_strdup(fmt->print);
	}
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	*ft_sharp_zero(t_format *fmt, char *sharp)
{
	char	*str;
	int		i;
	int		zeros;
	int		sharp_len;

	sharp_len = ft_strlen(sharp);
	i = ft_get_char_count_from_start(fmt->print, ' ');
	zeros = 0;
	if (fmt->option->precision + fmt->option->empty_width < fmt->option->width)
		zeros = ft_get_char_count_from_start(fmt->print + i, '0');
	if (i < 2)
		i = 2;
	if (zeros == 0)
	{
		if (fmt->option->flags->minus)
			return (ft_sharp_minus(fmt, sharp));
		else
			return (ft_sharp_plus(fmt, sharp));
	}
	ft_memmove(fmt->print + i - sharp_len, sharp, sharp_len);
	str = ft_strdup(fmt->print);
	if (str == NULL)
		return (NULL);
	return (str);
}

void	ft_flag_sharp(t_counter *cnt)
{
	t_format	*fmt;
	char		*str;
	char		*sharp;

	fmt = cnt->fmt;
	if (!fmt->option->flags->sharp || *((unsigned int *)fmt->value) == 0)
		return ;
	sharp = ft_get_sharp(fmt);
	if (sharp == NULL)
		return ;
	if (fmt->option->flags->zero)
		str = ft_sharp_zero(fmt, sharp);
	else if (fmt->option->flags->minus)
		str = ft_sharp_minus(fmt, sharp);
	else
		str = ft_sharp_plus(fmt, sharp);
	if (str == NULL)
		return ;
	ft_safer_free((void **)&sharp);
	ft_replace_print_str(fmt, str);
}
