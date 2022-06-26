# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhwang <sunhwang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 21:06:29 by sunhwang          #+#    #+#              #
#    Updated: 2022/06/08 20:49:22 by sunhwang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES: .o .c

NAME = libftprintf.a
CC = gcc
CFLGAS = -Wall -Wextra -Werror -g3 -fsanitize=address
ARFLAGS = rc
LDFLAGS = -L. -lftprintf
SRCS = ft_printf.c ft_printf_utils.c ft_operations.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cd libft
	make
	../
	$(AR) $(ARFLAGS) $@ $^

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

