SRC = main.cpp
FILES = ScalarConverter.cpp  	\

OBJ = $(SRC:.cpp=.o) $(FILES:.cpp=.o)
CXX = g++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -pedantic

NAME = Convert

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
