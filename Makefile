# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:25:38 by xamartin          #+#    #+#              #
#    Updated: 2020/03/21 20:54:34 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

#COMPILATION

CC = gcc
RM = rm -f
NAME = scop
LIBFT = libft/
LIBSDL2 = Frameworks/libsdl2
INC = includes/
CFLAGS = -Wall -Wextra -Werror -I $(INC) -I $(LIBFT) -O2 -g

#PATH

SRCS_PATH = ./srcs/
OBJS_PATH = ./srcs/

FILES = main.c \
        error/handle_error_parser.c \
        error/handle_error_sdl.c \
        parser/launch_parser.c \
        parser/reader.c \
		parser/parser_f_l.c \
		parser/parser_v.c \
		parser/line_checker.c \
		render/manage_sdl.c \
		tools/ft_atof.c \
		tools/init_obj.c \
		tools/init_ptr.c \
		tools/init_parser.c \
		tools/list_parser.c \
		tools/length_parser.c \
		tools/optionnal_argument.c \
		tools/pass_whitespace_float.c \


SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(addprefix $(OBJS_PATH), $(FILES:.c=.o))


#RULES

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L $(LIBFT) -lft -L $(LIBSDL2) -lSDL2-2.0.0


$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	@make -C $(LIBFT) clean
	@rm -f $(OBJS)

fclean: clean
	@rm -f libft/libft.a
	@rm -f $(NAME)

re: fclean all
