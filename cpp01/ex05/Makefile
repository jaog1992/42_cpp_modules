# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 20:52:59 by jde-orma          #+#    #+#              #
#    Updated: 2024/08/22 20:52:59 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Coder Alias
USER_NAME   = "jde-orma"

# Compiler and flags
CC          = c++
CCFLAGS     = -Wall -Wextra -Werror
CPP_VERSION = -std=c++98

# Colors:
DEF_COLOR	= \033[0;39m
BLUE		= \033[0;94m
GREEN		= \033[0;92m

# Directories:
SRC_DIR     = ./
INC_DIR     = ./
OBJ_DIR     = ./
BIN_DIR     = ./

# Files:
SRC_FILE	= main.cpp Harl.cpp
SRC         = $(addprefix $(SRC_DIR), $(SRC_FILE))

OBJ_FILE    = $(SRC_FILE:.cpp=.o)
OBJ         = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# Exec name:
NAME        = unnecessary_violence

# Binary directory placement:
CODE_BIN    = $(BIN_DIR)$(NAME)

# Default target
all: $(CODE_BIN)

# Linking target
$(CODE_BIN): $(OBJ)
	@$(CC) $(CCFLAGS) $(CPP_VERSION) $(OBJ) -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) compilation$(DEF_COLOR)"

# Rule for compiling .cpp files to .o files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@$(CC) $(CCFLAGS) $(CPP_VERSION) -c $< -o $@

# Ensure OBJ_DIR exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean .o files
clean:
	@$(RM) $(OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) .o files removal$(DEF_COLOR)"

# Clean executable and .o files
fclean: clean
	@$(RM) $(CODE_BIN)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) executable file removal$(DEF_COLOR)"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
