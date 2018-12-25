# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahugh <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 17:44:58 by ahugh             #+#    #+#              #
#    Updated: 2018/12/26 00:07:55 by ahugh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fillit

# directories

LIB_DIR			=	./libft
INC_DIR			=	./includes
SRC_DIR			=	./srcs

# files

SRC				=	fillit.c \
					get_tetriminos.c \
					square.c \
					tetrimino.c
OBJ				=	$(SRC:%.c=%.o)

# flags

CC				=	gcc
СFLAGS			=	-Wextra -Wall -Werror -c

# libs

LIB_FT			=	libft.a

.PHONY:			all clean fclean re

all: $(NAME)

$(NAME):
				@$(MAKE) -C $(LIB_DIR)
				@$(CC) $(СFLAGS) $(SRC)
				@$(CC) $(OBJ) $(LIB_DIR)/$(LIB_FT) -o $(NAME)

clean:
				@rm -f $(OBJ)

fclean: clean
				@$(MAKE) -C $(LIB_DIR) fclean
				@rm -f $(NAME)

re: fclean all
