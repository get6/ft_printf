/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:47:52 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 16:00:24 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

int	ft_get_char_count_from_start(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c)
			i++;
		else
			break ;
		str++;
	}
	return (i);
}
