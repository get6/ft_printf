# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 21:06:29 by sunhwang          #+#    #+#              #
#    Updated: 2022/07/09 22:46:25 by sunhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLGAS = -Wall -Wextra -Werror -g3 -fsanitize=address
ARFLAGS = rcs
LDFLAGS = -L. -lftprintf -L./libft -lft
SRCS = ft_checker.c ft_flags.c ft_node.c ft_operations.c ft_precision.c ft_utils.c ft_printf.c ft_stack.c ft_struct1.c ft_struct2.c ft_type1.c ft_type2.c ft_type3.c ft_width.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# $(NAME) : ref $(OBJS)
# 	cp ./libft/libft.a ./libftprintf.a
# 	$(AR) -q libftprintf.a $(OBJS)

$(NAME): ref $(OBJS)
	$(AR) $(ARFLAGS) libftprintf.a $(OBJS)
#	$(AR) $(ARFLAGS)T libftprintf.a libft/libft.a $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

%.o: %.c
	$(CC) $(CFLGAS) -c $<

re:
	$(MAKE) fclean
	$(MAKE) all

ref:
	$(MAKE) -C libft

main: main.o
	$(CC) $(CFLGAS) $^ $(LDFLAGS)

do: $(NAME) main

tre: fclean
	$(RM) main.o
	$(MAKE) do
