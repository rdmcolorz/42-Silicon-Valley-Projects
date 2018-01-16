# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 16:07:38 by tyang             #+#    #+#              #
#    Updated: 2018/01/15 13:13:44 by tyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly

FLAGS = -Wall -Wextra -Werror

SOURCE = main.c \
			read.c \
			map.c \
			move_map.c \
			helper.c \
			solve.c \
			memory.c \
		
OBJ = $(SOURCE:.c=.o)

$(NAME):
	@gcc $(FLAGS) $(SOURCE) -L. libft/libft.a -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re: fclean all
