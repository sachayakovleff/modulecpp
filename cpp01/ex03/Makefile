# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 15:07:14 by syakovle          #+#    #+#              #
#    Updated: 2023/08/29 16:38:31 by syakovle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp
FILES = Weapon.cpp		\
		HumanA.cpp		\
		HumanB.cpp

OBJ = $(SRC:.cpp=.o) $(FILES:.cpp=.o)
CC = g++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -pedantic

NAME = weapon

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re