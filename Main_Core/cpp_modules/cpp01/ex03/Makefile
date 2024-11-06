# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Name of the executable
NAME = violence

# Source files
SRCS = main.cpp \
       HumanA.cpp \
       HumanB.cpp \
       Weapon.cpp 

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re