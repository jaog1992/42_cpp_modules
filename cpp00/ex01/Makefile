# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 12:57:59 by jde-orma          #+#    #+#              #
#    Updated: 2024/08/17 15:21:30 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Coder Alias
USER_NAME   = "jde-orma"

# Compiler and flags
CC          = c++
CCFLAGS     = -Wall -Wextra -Werror
CPP_VERSION = -std=c++98

#Colors:

DEF_COLOR	= \033[0;39m
BLUE		= \033[0;94m
GREEN		= \033[0;92m

# Directories:

SRC_DIR     = ./
INC_DIR     = ./
OBJ_DIR     = ./
BIN_DIR     = ./

# Files:
SRC_FILE	= main.cpp Contact.cpp PhoneBook.cpp
SRC         = $(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ_FILE    = $(SRC_FILE:.cpp=.o)
OBJ         = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# Exec name:

NAME        = my_awesome_phonebook

# Binary directory placement:

CODE_BIN    = $(BIN_DIR)$(NAME)

all: $(CODE_BIN)

$(CODE_BIN): $(OBJ)
	@$(CC) $(CCFLAGS) $(CPP_VERSION) $(OBJ) -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) compilation$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) .o files removal$(DEF_COLOR)"

fclean:
	@$(RM) $(CODE_BIN) $(OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) executable file and .o files removal$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
