# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 14:28:26 by adrmarqu          #+#    #+#              #
#    Updated: 2024/08/10 14:00:29 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
MKDIR = mkdir -p
NAME = philo_bonus

SRC_F = get_data_bonus.c main_bonus.c utils_bonus.c \
		init_bonus.c philosophers_bonus.c init_data_bonus.c \
		pid_bonus.c sem_bonus.c actions_bonus.c

SRC_D = ./src/

OBJ_F = $(SRC_F:.c=.o)
OBJ_D = ./tmp/

SRC = $(addprefix $(SRC_D), $(SRC_F))
OBJ = $(addprefix $(OBJ_D), $(OBJ_F))

all: $(NAME)

$(NAME): $(OBJ_D) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Created philo"

$(OBJ_D)%.o: $(SRC_D)%.c Makefile inc/philo_bonus.h
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJ_D):
	@$(MKDIR) $(OBJ_D)

clean:
	@$(RM) $(OBJ_D)
	@echo "Deleted all '.o' and '.d'"

fclean: clean
	@$(RM) $(NAME)
	@echo "Deleted philo_bonus"

re : fclean all

.PHONY: all clean fclean re
