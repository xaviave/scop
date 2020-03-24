# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:25:38 by xamartin          #+#    #+#              #
#    Updated: 2020/03/24 18:21:58 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re
.SECONDEXPANSION:

#COMPILATION

CC = gcc
RM = rm -f
NAME = scop
FW = Frameworks/
FWGL = -framework OpenGl
LIBSDL2 = $(addprefix $(FW), libsdl2)
LIBGLEW = $(addprefix $(FW), libglew)
LIBFT = libft/
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
		tools/ft_atof.c \
		tools/init_obj.c \
		tools/init_ptr.c \
		tools/init_parser.c \
		tools/list_parser.c \
		tools/length_parser.c \
		tools/optional_argument.c \
		tools/pass_whitespace_number.c \
		render/launch_render.c \

SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(addprefix $(OBJS_PATH), $(FILES:.c=.o))

#RULES

all: $(NAME)

define define_mkdir_target
$(1):
	mkdir -p $(1)
endef

$(foreach dir,$(sort $(dir $(OBJS))),$(eval $(call define_mkdir_target,$(dir))))

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(FWGL) \
	-L $(LIBFT) -lft -L $(LIBSDL2) -lSDL2-2.0.0 -L $(LIBGLEW) -lGLEW.2.1.0

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC) | $$(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	@$(RM) $(OBJS)
	@echo "\033[31mScop objects deleted.\033[0m"

fclean: clean
	@$(RM) $(LIBFT)libft.a
	@$(RM) $(NAME)
	@echo "\033[31mScop binary deleted.\033[0m"

re: fclean all
