# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Name of the executable
NAME = sed

# Source files
SRCS = main.cpp 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re