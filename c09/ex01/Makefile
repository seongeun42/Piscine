CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
TARGET = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
INCLUDE = includes

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $< -I $(INCLUDE)

$(TARGET) : $(OBJS)
	ar -cr $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all
