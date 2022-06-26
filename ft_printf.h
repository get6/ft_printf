/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:26:31 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/25 18:15:41 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// TODO 이렇게 지정하지 않고 foramt 구조체에 해야할 함수들을 void * 배열로 넘겨주고 NULL을 만날때까지 함수를 처리하면 어떨까? 그 중에 하나라도 에러인 경우는 동작을 끝낸다.
# define D_CHARACTER 'c'
# define D_STRING 's'
# define D_POINTER 'p'
# define D_DECIMAL 'd'
# define D_INTEGER 'i'
# define D_UN_DECIMAL 'u'
# define D_LOWER_HEXA 'x'
# define D_UPPER_HEXA 'X'
# define D_PERCENT '%'
# define D_MINUS '-'
# define D_ZERO '0'
# define D_DOT '.'
# define D_SHARP '#'
# define D_BLANK ' '
# define D_PLUS '+'

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "ft_node.h"
# include <stdio.h> // for test

typedef struct s_counter
{
	int				total;
	int				length;
	struct s_format	*head;
}	t_counter;

typedef struct s_format
{
	char			flags;
	char			width;
	char			precision;
	char			size;
	char			type;
	void			*value;
	t_operation		**operations;
}	t_format;

// ft_printf.c
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_printf(const char *format, ...);

// ft_printf_utils.c
void	ft_safer_free(void **ptr);

// ft_operations.c
typedef t_format*	(*t_operation)(t_format, void *value);
void	ft_initialize_operations_array(t_operation *operations);
void	ft_evaluate_array(t_operation *operations, t_format *format);

// ft_struct.c
t_counter	*ft_counternew(void);

#endif
