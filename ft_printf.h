/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:26:31 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/05 21:22:15 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NULL (void *)0 // 왜 vscode가 모르지

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "ft_struct.h"
# include "ft_stack.h"
# include "ft_operations.h"

// ft_printf.c
int		ft_printf(const char *format, ...);

// ft_printf_utils.c
void	ft_safer_free(void **ptr);
void	ft_putchar(char c);
void	ft_putstr(char *s);

// ft_operations.c
void	ft_initialize_operations_array(t_operation *ops);
void	ft_get_format(t_counter *cnt, t_format *fmt, t_operation *ops);

// ft_checker.c
void	ft_check_flags(const char *str, t_format *fmt, t_operation *ops);
void	ft_check_width(const char *str, t_format *fmt, t_operation *ops);
void	ft_check_precision(const char *str, t_format *fmt, t_operation *ops);
void	ft_check_type(const char *str, t_format *fmt, t_operation *ops);

// ft_width.c
int		ft_get_width(char *str);

// ft_precision.c
int		ft_get_precision(const char *str);

// ft_struct.c
t_counter	*ft_counter_new(va_list ap);
t_format	*ft_format_new(void);

#endif
