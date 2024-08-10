# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 14:28:26 by adrmarqu          #+#    #+#              #
#    Updated: 2024/07/20 13:17:54 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
MKDIR = mkdir -p
NAME = philo
SANITAZE = -fsanitize=thread

SRC_F = actions.c atoi.c end.c get_data.c init.c init_data.c main.c	\
		mutex.c philosophers.c utils.c
SRC_D = ./src/

OBJ_F = $(SRC_F:.c=.o)
OBJ_D = ./tmp/

SRC = $(addprefix $(SRC_D), $(SRC_F))
OBJ = $(addprefix $(OBJ_D), $(OBJ_F))

all: $(NAME)

$(NAME): $(OBJ_D) $(OBJ)
	@$(CC) $(CFLAGS) -lpthread $(OBJ) -o $(NAME)
	@echo "Created philo"

$(OBJ_D)%.o: $(SRC_D)%.c Makefile inc/philo.h
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJ_D):
	@$(MKDIR) $(OBJ_D)

clean:
	@$(RM) $(OBJ_D)
	@echo "Deleted all '.o' and '.d'"

fclean: clean
	@$(RM) $(NAME)
	@echo "Deleted philo"

re : fclean all

.PHONY: all clean fclean re
