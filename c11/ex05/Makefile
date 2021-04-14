CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = do-op
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
HEAD = -I.

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< $(HEAD)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re
