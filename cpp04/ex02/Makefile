SRC = main.cpp
FILES = Animal.cpp  	\
		Cat.cpp			\
		Dog.cpp			\
		WrongAnimal.cpp	\
		WrongCat.cpp	\
		Brain.cpp

OBJ = $(SRC:.cpp=.o) $(FILES:.cpp=.o)
CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -pedantic

NAME = animal

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re