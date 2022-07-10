/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:47:52 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/10 22:22:05 by sunhwang         ###   ########.fr       */
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

static int	ft_recursive_putnbr(char **str, long long n, char *base, int s_len)
{
	int	i;
	int	b_len;

	i = 0;
	b_len = ft_strlen(base);
	if (n == 0)
	{
		*str = (char *)malloc(s_len - 1);
		if (*str == NULL)
			return (-1);
		*(*str + (s_len - 2)) = '\0';
		return (0);
	}
	i = ft_recursive_putnbr(str, n / b_len, base, s_len + 1);
	if (i == -1)
		return (i);
	*(*str + i) = *(base + (n % b_len));
	return (i + 1);
}

char	*ft_putnbr_base(long long nbr, char *base)
{
	char	*res;

	res = NULL;
	if (nbr == 0)
	{
		res = (char *)malloc(2);
		if (res == NULL)
			return (NULL);
		*res = '0';
		*(res + 1) = '\0';
		return (res);
	}
	ft_recursive_putnbr(&res, nbr, base, 1);
	return (res);
}

int	ft_is_negative(t_format *fmt)
{
	int	minus;

	minus = 0;
	if (ft_is_same_type(fmt, 'd') || ft_is_same_type(fmt, 'i'))
		minus = *((int *)fmt->value) < 0;
	else if (ft_is_same_type(fmt, 'u'))
		minus = *((unsigned int *)fmt->value) < 0;
	else if (ft_is_same_type(fmt, 'x') || ft_is_same_type(fmt, 'X'))
		minus = *((long long *)fmt->value) < 0;
	return (minus);
}