# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:25:38 by xamartin          #+#    #+#              #
#    Updated: 2020/03/13 13:26:19 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

#COMPILATION

CC = gcc
RM = rm -f
NAME = scop
LIBFT = libft/
FW = Frameworks/
LIBSDL2 = $(addprefix $(FW), libsdl2)
LIBGLEW = $(addprefix $(FW), libglew)
INC = includes/
CFLAGS = -Wall -Wextra -I $(INC) -I $(LIBFT) -O2 -g
# LIB_FLAG = -framework OpenGl -framework AppKit

#PATH

SRCS_PATH = ./srcs/
OBJS_PATH = ./srcs/

FILES = main.c \
        error/handle_error_parser.c \
        error/handle_error_sdl.c \
        parser/launch_parser.c \
        parser/reader.c \
        tools/list_parser.c \
		render/launch_render.c \


SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(addprefix $(OBJS_PATH), $(FILES:.c=.o))


#RULES

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L $(LIBFT) -lft -L $(LIBSDL2) -lSDL2-2.0.0 -L $(LIBGLEW) -lGLEW.2.1.0


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	@make -C $(LIBFT) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f libft/libft.a
	@rm -f $(NAME)

re: fclean all
