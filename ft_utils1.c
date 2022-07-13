/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:47:52 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/13 21:12:58 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_safer_free(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(char *s)
{
	int	s_len;

	if (s == NULL)
		return ;
	s_len = ft_strlen(s);
	write(STDOUT_FILENO, s, s_len);
}

char	ft_getchar(const char *str, t_format *fmt)
{
	int		i;
	char	c;

	i = *(fmt->index);
	c = *(str + i);
	return (c);
}

int	ft_check_total(t_counter *cnt, int length)
{
	if (cnt->total + length < 2147483647)
		cnt->total += length;
	else
	{
		cnt->total = -1;
		return (0);
	}
	return (1);
}
