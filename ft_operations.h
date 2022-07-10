/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:41:13 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/08 19:41:32 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPERATIONS_H
# define FT_OPERATIONS_H

# include "ft_struct.h"

// ft_flags.c
void	ft_flag_minus(t_counter *cnt, t_format *fmt);
void	ft_flag_zero(t_counter *cnt, t_format *fmt);
void	ft_flag_sharp(t_counter *cnt, t_format *fmt);
void	ft_flag_blank(t_counter *cnt, t_format *fmt);
void	ft_flag_plus(t_counter *cnt, t_format *fmt);

// ft_width.c
void	ft_calc_width(t_counter *cnt, t_format *fmt);

// ft_precision.c
void	ft_calc_precision(t_counter *cnt, t_format *fmt);

// ft_type1.c
void	ft_type_char(t_counter *cnt, t_format *fmt);
void	ft_type_string(t_counter *cnt, t_format *fmt);
void	ft_type_pointer(t_counter *cnt, t_format *fmt);
void	ft_type_decimal(t_counter *cnt, t_format *fmt);
void	ft_type_integer(t_counter *cnt, t_format *fmt);

// ft_type2.c
void	ft_type_usigned_decimal(t_counter *cnt, t_format *fmt);
void	ft_type_lower_hexadecimal(t_counter *cnt, t_format *fmt);
void	ft_type_upper_hexadecimal(t_counter *cnt, t_format *fmt);
void	ft_type_percent(t_counter *cnt, t_format *fmt);

#endif
