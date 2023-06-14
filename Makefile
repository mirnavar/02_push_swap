# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 15:10:14 by mirnavar          #+#    #+#              #
#    Updated: 2023/06/14 16:35:56 by mirnavar         ###   ########.fr        #
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
LIBFT		= lib/libft.a
LIBPF		= lib/ft_printf.a
LIB			= lib/

# ---------------- SOURCES ------------------- #

SRC			= src/init_stack.c		\
			  src/check.c			\
			  src/mov/swap.c		\
			  src/mov/push.c		\
			  src/mov/rotate.c		\
			  src/mov/rev_rotate.c	\
			  src/sort/3_to_5.c		\
			  src/sort/sorted.c		\
			  src/sort/others.c		\
			  src/sort/utils.c		
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

$(NAME):	$(OBJ) $(LIBFT) $(LIBPF)
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
