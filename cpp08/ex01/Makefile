# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/04 18:57:22 by jde-orma          #+#    #+#              #
#    Updated: 2026/01/04 18:57:24 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

SRCS = main.cpp\
       Span.cpp\

OBJS = main.o\
       Span.o\

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

$(OBJS): %.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean all