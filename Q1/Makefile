NAME	=	q1

SRCS	=	main.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	 -W -Wall -Werror -Wextra -std=gnu99

CC	=	gcc

RM	=	rm -rf

all:		$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
		$(RM) *~

re:		fclean all

.PHONY:		all clean fclean re
