# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamartin <xamartin@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 13:25:38 by xamartin          #+#    #+#              #
#    Updated: 2020/04/09 22:23:35 by xamartin         ###   ########lyon.fr    #
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
CFLAGS = -Wall -Wextra -Werror -I $(INC) -I $(LIBFT) -O2 -g
PY = python3
TESTER = "data/tests/test_code.py"

#PATH

SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/

FILES = main.c \
		error/handle_error_sdl.c \
		error/handle_error_parser.c \
		parser/reader.c \
		parser/launch_parser.c \
		parser/line_checker/check_obj.c \
		parser/line_checker/check_mtl.c \
		parser/line_checker/line_checker.c \
		parser/line_checker/basic_line_checker.c \
		parser/line_checker/advanced_obj_checker.c \
		parser/object/print_obj.c \
		parser/object/list_parser_to_obj.c \
		parser/object/definitions/parser_v.c \
		parser/object/definitions/parser_f_l_o_g_pass.c \
		parser/material/print_mtl.c \
		parser/material/list_parser_to_mtl.c \
		parser/material/files/parse_file.c \
		parser/material/definitions/parser_k.c \
		parser/material/definitions/parse_color.c \
		parser/material/definitions/parser_tf_d_s_ni.c \
		parser/material/definitions/parsing_texture_option.c \
		parser/material/definitions/parser_sharp_bump_decal_illum_pass.c \
		tools/char.c \
		tools/path.c \
		tools/ft_atof.c \
		tools/define_id.c \
		tools/list_parser.c \
		tools/length_parser.c \
		tools/pass_whitespace.c \
		tools/manage_addr.c \
		tools/spec_delete_obj.c \
		tools/details_delete_obj.c \
		tools/optional_argument.c \
		tools/init/init_obj.c \
		tools/init/init_ptr.c \
		tools/init/init_mtl.c \
		tools/init/init_prog.c \
		tools/init/init_parser.c \
		tools/init/init_parser_option.c \
		tools/init/init_texture_option.c \
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
