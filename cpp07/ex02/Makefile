# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/31 18:08:36 by jde-orma          #+#    #+#              #
#    Updated: 2026/01/10 16:24:00 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array

SRCS = main.cpp\

OBJS = main.o\

CC = c++

CCFLAGS     = -Wall -Wextra -Werror
CPP_VERSION = -std=c++98

USER_NAME   = "jde-orma"

DEF_COLOR	= \033[0;39m
BLUE		= \033[0;94m
GREEN		= \033[0;92m

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CCFLAGS) $(CPP_VERSION) $^ -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) compilation$(DEF_COLOR)"

$(OBJS): %.o: %.cpp
	@$(CC) $(CCFLAGS) $(CPP_VERSION) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) .o files removal$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) executable file removal$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re