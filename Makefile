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
CFLAGS			= -I $(HEADER_DIR) -I libft/includes/ -I minilibx_macos/ # -Wall -Werror -Wextra -O2 -O3

SRC				= src/main.c \
				  src/file_get_contents.c \
				  src/utils.c \
				  src/init.c \
				  src/renderer/init.c \
				  src/renderer/lines.c \
				  src/renderer/functions.c \
				  src/renderer/renderer.c \
				  src/renderer/camera.c \
				  src/renderer/display.c


LIB =			  libft/libft.a

OBJ = $(patsubst %.c,%.o,$(SRC))

%.o: %.c $(HEADER)
	@gcc -c $(CFLAGS) $< -o $@
	@printf "."

all: lib $(NAME)

$(NAME): $(OBJ) $(LIB)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)  -L libft -lft -L minilibx_macos/ -lmlx  -framework OpenGL -framework AppKit
	@printf "\nDone\n"

$(LIB):

lib:
	@make -C libft

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@printf "Clean\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@printf "FClean\n"

re: fclean all

.PHONY: clean fclean all re
