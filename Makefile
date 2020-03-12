# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 11:27:57 by xamartin          #+#    #+#              #
#    Updated: 2020/03/12 11:29:37 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

#COMPILATION

CC = gcc
RM = rm -f
NAME = scop
LIBFT = libft/
INC = includes/scop.h
CFLAGS = -Wall -Wextra -Werror -O2 -g 
# LIB_FLAG = -framework OpenGl -framework AppKit

#PATH

SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/

FILES = main.c \
		parser/launch_parser.c \

SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(addprefix $(OBJS_PATH), $(FILES:.c=.o))


#RULES

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MINILIBX) -L $(LIBFT) -lft


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	@make -C $(LIBFT) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f libft/libft.a
	@rm -f $(NAME)

re: fclean all
