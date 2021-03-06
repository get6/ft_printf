/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:26:31 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 18:55:25 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "ft_struct.h"
# include "ft_stack.h"
# include "ft_operations.h"

// ft_printf.c
int			ft_printf(const char *format, ...);

// ft_utils1.c
void		ft_safer_free(void **ptr);
void		ft_putchar(char c);
void		ft_putstr(char *s);
char		ft_getchar(const char *str, t_format *fmt);
int			ft_get_char_count_from_start(const char *str, char c);

// ft_utils2.c
char		*ft_putnbr_base(unsigned long long nbr, char *base);
int			ft_is_minus(t_format *fmt);
char		*ft_delete_minus(long long n);
void		ft_replace_print_str(t_format **fmt, char **new);

// ft_utils3.c
int			ft_get_last_flag_index(t_format *fmt);
int			ft_get_first_blank_index_from_end(t_format *fmt);

// ft_checker.c
void		ft_check_flags(const char *str, t_format *fmt, t_operation *ops);
void		ft_check_width(const char *str, t_format *fmt, t_operation *ops);
void		ft_check_precision(const char *str, t_format *fmt, \
t_operation *ops);
void		ft_check_type(const char *str, t_format *fmt, t_operation *ops);

// ft_struct1.c
t_counter	*ft_counter_new(va_list *ap);
t_format	*ft_format_new(void);

// ft_struct2.c
void		ft_format_free(t_format **p_fmt);

#endif
