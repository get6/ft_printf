/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:34:05 by sunhwang          #+#    #+#             */
/*   Updated: 2022/07/16 21:49:02 by sunhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_counter	*ft_counter_new(va_list *ap)
{
	t_counter	*new;

	new = (t_counter *)malloc(sizeof(t_counter));
	if (new == NULL)
		return (NULL);
	new->total = 0;
	new->ap = ap;
	new->fmt = NULL;
	return (new);
}

static t_flag	*ft_flag_new(void)
{
	t_flag	*new;

	new = (t_flag *)malloc(sizeof(t_flag));
	if (new == NULL)
		return (NULL);
	new->plus = 0;
	new->minus = 0;
	new->blank = 0;
	new->sharp = 0;
	new->zero = 0;
	return (new);
}

static t_option	*ft_optional_new(void)
{
	t_option	*new;

	new = (t_option *)malloc(sizeof(t_option));
	if (new == NULL)
		return (NULL);
	new->flags = ft_flag_new();
	if (new->flags == NULL)
	{
		ft_safer_free((void **)&new);
		return (NULL);
	}
	new->width = 0;
	new->empty_width = 0;
	new->precision = 0;
	return (new);
}

static t_stack	*ft_stack_new(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	initialize_stack(new);
	return (new);
}

t_format	*ft_format_new(void)
{
	t_format	*new;

	new = (t_format *)malloc(sizeof(t_format));
	if (new == NULL)
		return (NULL);
	new->option = ft_optional_new();
	if (new->option == NULL)
	{
		ft_safer_free((void **)&new);
		return (NULL);
	}
	new->operations = ft_stack_new();
	if (new->operations == NULL)
	{
		ft_safer_free((void **)&new->option);
		ft_safer_free((void **)&new);
		return (NULL);
	}
	new->print = NULL;
	new->index = NULL;
	new->length = 0;
	new->type = '\0';
	return (new);
}
