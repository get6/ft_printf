/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:47:52 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/07 23:20:24 by sunhwang         ###   ########.fr       */
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
	write(1, s, s_len + 1);
}

char	ft_getchar(const char *str, t_format *fmt)
{
	int		i;
	char	c;

	i = *(fmt->index);
	c = *(str + i);
	return (c);
}

