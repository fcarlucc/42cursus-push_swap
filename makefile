# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 12:07:55 by fcarlucc          #+#    #+#              #
#    Updated: 2023/06/21 17:41:23 by fcarlucc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC = main.c \

SRC1 = push_swap.c utils.c quicksort.c sort.c push.c swap.c rot.c rev_rot.c \

SRC2 = push_swap_bonus.c push_swap_utils_bonus.c \

OBJ = $(SRC:.c=.o)

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

#COLORS
RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

BLUE = \033[1;34m

DEFAULT = \033[0m

all :
	@$(CC) $(FLAGS) $(SRC) $(SRC1) -o $(NAME)
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

bonus : all
	@$(CC) $(FLAGS) $(SRC1) $(SRC2) -o $(NAME_BONUS)
	@echo "$(BLUE)$(NAME_BONUS) created!$(DEFAULT)"

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ1)
	@rm -f $(OBJ2)
	@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(RED)all deleted!$(DEFAULT)"

re: fclean all

.PHONY:			all bonus clean fclean re