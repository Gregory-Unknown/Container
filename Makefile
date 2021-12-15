NAME	= Container
SRCS	= main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
#-std=c++98  -fsanitize=address
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
