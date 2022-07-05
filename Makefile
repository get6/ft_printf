# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 21:06:29 by sunhwang          #+#    #+#              #
#    Updated: 2022/07/05 21:56:05 by sunhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .o .c

NAME = libftprintf.a
CC = gcc
CFLGAS = -Wall -Wextra -Werror -g3 -fsanitize=address
ARFLAGS = rc
LDFLAGS = -L. -lftprintf -L./libft -lft
SRCS = ft_checker.c ft_flags.c ft_node.c ft_operations.c ft_precision.c ft_printf_utils.c ft_printf.c ft_stack.c ft_struct.c ft_type1.c ft_type2.c ft_width.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cd ./libft && $(MAKE) fclean && $(MAKE) all
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLGAS) -c $<

clean:
	$(RM) $(OBJS) main.o

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

main: main.o
	$(CC) $(CFLGAS) $(LDFLAGS) $^

com: $(NAME) main

