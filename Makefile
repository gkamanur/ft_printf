# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 15:11:25 by gkamanur          #+#    #+#              #
#    Updated: 2024/12/10 15:16:00 by gkamanur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Source files and corresponding object files
SRC = ft_printf.c ft_printf_util.c
OBJ = $(SRC:.c=.o)

# Default rule to create the library
all: $(NAME)

# Rule to create the library from object files
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created."

# Rule to compile each .c file to .o file
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	rm -f $(OBJ)
	@echo "Object files removed."

# Rule to clean object files and the library
fclean: clean
	rm -f $(NAME)
	@echo "Library $(NAME) removed."

# Rule to recompile everything
re: fclean all

# Rule to run the code using the library
run: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o a.out
	./a.out

# Declare phony targets
.PHONY: all clean fclean re run
