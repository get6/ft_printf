/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:53:42 by sunhwang          #+#    #+#             */
/*   Updated: 2022/06/28 20:54:04 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

typedef struct s_flag
{
	char	plus;
	char	minus;
	char	space;
	char	hash;
	char	zero;
}	t_flag;

typedef struct s_counter
{
	int		total;
	int		length;
	t_queue	*head;
}	t_counter;

typedef struct s_format
{
	t_flag			flags;
	char			width;
	char			precision;
	char			size;
	char			type;
	void			*value;
	void			*operations;
}	t_format;

#endif
