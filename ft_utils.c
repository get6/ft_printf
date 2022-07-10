/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:47:52 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/09 22:35:18 by sunhwang         ###   ########.fr       */
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

static void	ft_recursive_putnbr(char **str, size_t n, char *base, int s_len)
{
	int	b_len;

	b_len = ft_strlen(base);
	if (n == 0)
	{
		*str = (char *)malloc(s_len + 1);
		if (*str == NULL)
			return ;
		*(*str + s_len) = '\0';
	}
	ft_recursive_putnbr(str, n / b_len, base, s_len + 1);
	if (*str == NULL)
		return ;
	*(*str + s_len) = '0' + *(base + (n % b_len));
}

char	*ft_putnbr_base(size_t nbr, char *base)
{
	char	*res;

	ft_recursive_putnbr(&res, nbr, base, 1);
	return (res);
}
