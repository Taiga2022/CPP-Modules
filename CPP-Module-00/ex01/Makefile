NAME := phonebook

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := -Iincludes

SRCS_DIR := srcs
OBJS_DIR := objs

SRCS := main.cpp \
		Contact.cpp \
		PhoneBook.cpp
OBJS := $(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	./tests/test.sh ./$(NAME)

-include $(DEPS)
