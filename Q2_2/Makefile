NAME	=	Q2_2

SRCS	=	main.cpp \
		md5.cpp	

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS	=	-std=gnu++11 -pthread
# CXXFLAGS	=	-std=gnu++11 -W -Werror -Wall -Wextra -pthread

CXX	=	c++

RM	=	rm -rf

all:		$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
		$(RM) *~

re:		fclean all

.PHONY:		all clean fclean re
