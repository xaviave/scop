# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:25:38 by xamartin          #+#    #+#              #
#    Updated: 2020/03/24 17:48:39 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


.PHONY: all init clean fclean re

#COMPILATION

CC = gcc
RM = rm -f
NAME = scop
LIBFT = libft/
FW = Frameworks/
FWGL = -framework OpenGl
LIBSDL2 = $(addprefix $(FW), libsdl2)
LIBGLEW = $(addprefix $(FW), libglew)
INC = includes/
CFLAGS = -Wall -Wextra -I $(INC) -I $(LIBFT) -O2 -g

#PATH

SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/

FILES = main.c \
		error/handle_error_parser.c \
		error/handle_error_sdl.c \
		parser/launch_parser.c \
		parser/reader.c \
		parser/parser_f_l.c \
		parser/parser_v.c \
		parser/line_checker.c \
		render/launch_render.c \
		tools/ft_atof.c \
		tools/init_obj.c \
		tools/init_ptr.c \
		tools/init_parser.c \
		tools/list_parser.c \
		tools/length_parser.c \
		tools/optional_argument.c \
		tools/pass_whitespace_number.c \


SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(addprefix $(OBJS_PATH), $(FILES:.c=.o))


#RULES

init:
	@mkdir -p objs
	@mkdir -p objs/parser/
	@mkdir -p objs/render/
	@mkdir -p objs/tools/
	@mkdir -p objs/error/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(FWGL) \
	-L $(LIBFT) -lft -L $(LIBSDL2) -lSDL2-2.0.0 -L $(LIBGLEW) -l GLEW.2.1.0


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	@make -C $(LIBFT) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f libft/libft.a
	@rm -f $(NAME)

re: fclean all
