NAME := megaphone

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := megaphone.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all run test clean fclean re

all: $(NAME)

run: $(NAME)
	./$(NAME) $(ARGS)

test: $(NAME)
	sh tests/test.sh ./$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)
