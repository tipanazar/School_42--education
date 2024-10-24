# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Name of the executable
NAME = zombies

# Source files
SRCS = main.cpp \
       newZombie.cpp \
	   randomChump.cpp \
       Zombie.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Zombie.hpp 

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