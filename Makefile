# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjamie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 19:57:44 by sjamie            #+#    #+#              #
#    Updated: 2019/11/12 19:57:45 by sjamie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

CC				= gcc
HEADER_DIR		= includes/
HEADER			= includes/fdf.h
CFLAGS			= -I $(HEADER_DIR)# -Wall -Werror -Wextra -O2 -O3

SRC				= src/main.c \
				  src/file_get_contents.c \
				  src/utils.c \
				  src/init.c

LIB =			  libft/libft.a

OBJ = $(patsubst %.c,%.o,$(SRC))

%.o: %.c $(HEADER)
	gcc -c $(CFLAGS) $< -o $@

all: lib $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -L libft -lft

$(LIB):

lib:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
