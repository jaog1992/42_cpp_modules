# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 15:17:46 by jde-orma          #+#    #+#              #
#    Updated: 2025/12/31 15:47:54 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER_NAME   = "jde-orma"

CC          = c++
CCFLAGS     = -Wall -Wextra -Werror
CPP_VERSION = -std=c++98

DEF_COLOR	= \033[0;39m
BLUE		= \033[0;94m
GREEN		= \033[0;92m

SRC_DIR     = ./
INC_DIR     = ./
OBJ_DIR     = ./
BIN_DIR     = ./

SRC_FILE	= main.cpp ScalarConverter.cpp
SRC         = $(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ_FILE    = $(SRC_FILE:.cpp=.o)
OBJ         = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

NAME        = convert

CODE_BIN    = $(BIN_DIR)$(NAME)

all: $(CODE_BIN)

$(CODE_BIN): $(OBJ)
	@$(CC) $(CCFLAGS) $(CPP_VERSION) $(OBJ) -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) compilation$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@$(CC) $(CCFLAGS) $(CPP_VERSION) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) .o files removal$(DEF_COLOR)"

fclean: clean
	@$(RM) $(CODE_BIN)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) executable file removal$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re