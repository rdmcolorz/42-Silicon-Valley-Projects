# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 16:07:38 by tyang             #+#    #+#              #
#    Updated: 2018/02/07 15:18:49 by tyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
FLAGS = -Wall -Wextra -Werror
LIBFT = -L. libft/libft.a
FRAME = -framework OpenGL -framework AppKit minilibx/libmlx.a
SOURCE = main.c keyboard.c mouse.c get_next_line.c readmap.c debug.c draw.c \
			raycasting.c
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I includes/wolf3d.h $(LIBFT) $(FRAME) $(SOURCE) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re: fclean all
