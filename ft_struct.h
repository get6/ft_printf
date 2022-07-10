/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:53:42 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/10 15:16:26 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include <stdarg.h>

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
}	t_node;

typedef struct s_linked_list
{
	t_node	*head;
	t_node	*tail;
	t_node	*current;
}	t_linked_list;

typedef t_linked_list	t_stack;

typedef struct s_flag
{
	char	plus;
	char	minus;
	char	blank;
	char	sharp;
	char	zero;
}	t_flag;

typedef struct s_counter
{
	int		total;
	va_list	*ap;
}	t_counter;

typedef struct s_option
{
	t_flag	*flags;
	char	width;
	char	precision;
}	t_option;

typedef struct s_format
{
	void		*value;
	char		*print;
	int			*index;
	int			length;
	char		type;
	t_option	*option;
	t_stack		*operations;
}	t_format;

typedef void			(*t_operation)(t_counter *cnt, t_format *fmt);

#endif
