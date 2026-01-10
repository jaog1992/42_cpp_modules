# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/10 17:08:53 by jde-orma          #+#    #+#              #
#    Updated: 2026/01/10 17:08:56 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ex00
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
INCLUDES    = -I includes

SRC_DIR     = src
MAIN_SRCS   = main.cpp BitcoinExchange.cpp

SRCS = $(addprefix $(SRC_DIR)/, $(MAIN_SRCS))

OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

DIRS = $(OBJ_DIR)

all: $(DIRS) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
