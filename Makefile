NAME	= getnextline
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -D BUFFER_SIZE=1
RM		= rm -f

INC		= get_next_line.h
SRCS	= get_next_line.c \
		  get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re