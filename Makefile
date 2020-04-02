# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:25:38 by xamartin          #+#    #+#              #
#    Updated: 2020/04/02 17:37:42 by xamartin         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re test
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
PY = python3
TESTER = "data/tests/test_code.py"

#PATH

SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/

FILES = main.c \
		error/handle_error_parser.c \
		error/handle_error_sdl.c \
		parser/reader.c \
		parser/line_checker.c \
		parser/launch_parser.c \
		parser/object/parser_v.c \
		parser/object/print_obj.c \
		parser/object/parser_f_l_o_g_pass.c \
		parser/object/list_parser_to_obj.c \
		parser/material/parser_k.c \
		parser/material/parser_tf_d_s_ni.c \
		parser/material/parser_sharp_bump_decal_illum_pass.c \
		parser/material/print_mtl.c \
		parser/material/parse_file.c \
		parser/material/parse_color.c \
		parser/material/parsing_texture_option.c \
		parser/material/list_parser_to_mtl.c \
		tools/char.c \
		tools/path.c \
		tools/ft_atof.c \
		tools/init_obj.c \
		tools/init_ptr.c \
		tools/init_mtl.c \
		tools/init_parser.c \
		tools/init_parser_option.c \
		tools/list_parser.c \
		tools/length_parser.c \
		tools/optional_argument.c \
		tools/pass_whitespace.c \
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

test:
	@$(PY) $(TESTER)
