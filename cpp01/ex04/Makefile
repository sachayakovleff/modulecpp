# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 15:07:14 by syakovle          #+#    #+#              #
#    Updated: 2023/09/27 16:42:32 by syakovle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp


OBJ = $(SRC:.cpp=.o)
CXX = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -g3 -std=c++98 -pedantic

NAME = forwinner

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re