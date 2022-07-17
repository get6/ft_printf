/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:13:00 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 11:39:27 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_is_minus(t_format *fmt)
{
	int	minus;

	minus = 0;
	if (ft_is_same_type(fmt, 'd') || ft_is_same_type(fmt, 'i'))
		minus = *((int *)fmt->value) < 0;
	else if (ft_is_same_type(fmt, 'u'))
		minus = *((unsigned int *)fmt->value) < 0;
	else if (ft_is_same_type(fmt, 'x') || ft_is_same_type(fmt, 'X'))
		minus = *((unsigned int *)fmt->value) < 0;
	return (minus);
}

char	*ft_delete_minus(long long n)
{
	int		str_len;
	char	*res;
	char	*str;

	str = ft_itoa(n);
	if (str == NULL)
		return (NULL);
	if (0 <= n)
		return (str);
	str_len = ft_strlen(str);
	res = (char *)malloc(str_len - 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, str + 1, str_len);
	return (res);
}

void	ft_replace_print_str(t_format *fmt, char *new)
{
	if (!fmt->print)
		free(fmt->print);
	fmt->print = new;
	fmt->length = ft_strlen(new);
}
