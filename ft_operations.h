/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:41:13 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/17 12:37:03 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATIONS_H
# define FT_OPERATIONS_H

# include "ft_struct.h"

// ft_operations.c
void	ft_initialize_operations_array(t_operation *ops);
void	ft_get_format(t_counter *cnt);

// ft_flags1.c
char	*ft_copy_str_with_flag(const char *src, char flag, int length);
void	ft_flag_minus(t_counter *cnt);
void	ft_flag_zero(t_counter *cnt);

// ft_flags2.c
void	ft_flag_plus(t_counter *cnt);
void	ft_flag_blank(t_counter *cnt);

// ft_flags3.c
void	ft_flag_sharp(t_counter *cnt);

// ft_width.c
int		ft_get_width(const char *str, t_format *fmt);
void	ft_calc_width(t_counter *cnt);

// ft_precision.c
int		ft_get_precision(const char *str, t_format *fmt);
void	ft_calc_precision(t_counter *cnt);

// ft_type1.c
void	ft_type_char(t_counter *cnt);
void	ft_type_string(t_counter *cnt);
void	ft_type_pointer(t_counter *cnt);
void	ft_type_decimal(t_counter *cnt);
void	ft_type_integer(t_counter *cnt);

// ft_type2.c
void	ft_type_usigned_decimal(t_counter *cnt);
void	ft_type_lower_hexadecimal(t_counter *cnt);
void	ft_type_upper_hexadecimal(t_counter *cnt);
void	ft_type_percent(t_counter *cnt);
char	*ft_char_to_string(char c);

// ft_type3.c
int		ft_is_same_type(t_format *fmt, char c);
int		ft_is_nul(t_format *fmt);
void	ft_calc_minus(t_counter *cnt);

#endif
