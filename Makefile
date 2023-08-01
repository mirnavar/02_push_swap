# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 15:10:14 by mirnavar          #+#    #+#              #
#    Updated: 2023/08/01 17:37:41 by mirnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------- VARIABLES ------------------ #

NAME 		= push_swap
MKFL		= Makefile
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Werror -Wextra -g

# --------------- LIBRARIES ------------------ #

PSW_HEADER	= inc/push_swap.h
LIBFT		= 00_libft/libft.a
LIB			= 00_libft/

# ---------------- SOURCES ------------------- #

SRC			= src/instructions/push.c src/instructions/swap.c \
			 src/instructions/reverse_rotate.c src/instructions/rotate.c \
			 src/check.c src/free.c src/init.c src/main.c \
			 src/sort/lets_sort.c src/sort/sorted.c \
			 src/sort/utils_sort.c 
INC			= -I ./inc

# --------------- DIRECTORIES --------------- #

OBJ_DIR		= src/obj
#.o
OBJ			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEP			= $(addsuffix .d, $(basename $(OBJ)))

# ------------------ RULES ------------------ #

all:
			@$(MAKE) -C $(LIB)
			@$(MAKE) $(NAME)

$(OBJ_DIR)%.o: %.c $(MKFL)
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -MMD -c $< -o $@ $(INC)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBPF) -o $(NAME)
			@echo "Push swap correctly compiled"

-include $(DEP)

clean:
			@make clean -C $(LIB)
			$(RM) $(OBJ_DIR)
			@echo "Object files cleaned"

fclean:		clean
			@make fclean -C $(LIB)
			$(RM) $(NAME)
			@echo "Executable files and name cleaned"
re:			fclean all

.PHONY: 	clean fclean re
