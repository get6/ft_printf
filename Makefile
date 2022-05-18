.SUFFIXES: .o .c

NAME = libftprintf.a
CC = gcc
CFLGAS = -Wall -Wextra -Werror -g3 -fsanitize=address
ARFLAGS = rc
LDFLAGS = -L. -lftprintf
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
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
