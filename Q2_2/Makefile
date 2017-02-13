NAME	=	Q2_2

SRCS	=	main.cpp \
		md5.cpp	

OBJS	=	$(SRCS:.cpp=.o)

CFLAGS	=	-W -Werror -Wall -Wextra -std=c++11

CC	=	g++

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
