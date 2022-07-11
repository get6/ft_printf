/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:15:05 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/11 15:56:51 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_same_type(t_format *fmt, char c)
{
	return (fmt->type == c);
}

int	ft_is_nul(t_format *fmt)
{
	return (ft_is_same_type(fmt, 'c') && *(char *)fmt->value == '\0');
}

void	ft_calc_minus(t_counter *cnt, t_format *fmt)
{
	char	c;
	int		i;
	int		str_len;
	char	*str;

	if (!ft_is_minus(fmt))
		return ;
	(void)cnt;
	i = 0;
	str_len = ft_strlen(fmt->print);
	str = (char *)malloc(str_len + 1);
	if (str == NULL)
		return ;
	while (*(fmt->print + i) != '\0')
	{
		c = *(fmt->print + i);
		if (ft_isdigit(c))
			break ;
		*(str + i++) = c;
	}
	*(str + i) = '-';
	ft_strlcpy(str + 1 + i, fmt->print + i, str_len + 1);
	free(fmt->print);
	fmt->print = str;
}
